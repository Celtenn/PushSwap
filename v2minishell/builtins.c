#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern int g_exit_status;

static int	is_numeric(const char *str)
{
	int i = 0;
	if (!str)
		return 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit((unsigned char)str[i]))
			return 0;
		i++;
	}
	return 1;
}

/*int builtin_cd(char **argv)
{
	if (!argv[1]) {
		fprintf(stderr, "cd: missing argument\n");
		g_exit_status = 1;
		return 1;
	}
	if (chdir(argv[1]) != 0) {
		perror("cd");
		g_exit_status = 1;
		return 1;
	}
	g_exit_status = 0;
	return 0;
}*/

void	update_env_var(const char *entry, t_shell *shell)
{
	char *equal = strchr(entry, '=');
	if (!equal)
		return;

	int name_len = equal - entry;
	char *name = strndup(entry, name_len);
	if (!name)
		return;

	// Eski varsa sil
	for (int i = 0; shell->env[i]; i++)
	{
		if (strncmp(shell->env[i], name, name_len) == 0 && shell->env[i][name_len] == '=')
		{
			free(shell->env[i]);
			for (int k = i; shell->env[k]; k++)
				shell->env[k] = shell->env[k + 1];
			break;
		}
	}

	// Yeniyi ekle
	int count = 0;
	while (shell->env[count])
		count++;
	shell->env = realloc(shell->env, sizeof(char *) * (count + 2));
	shell->env[count] = strdup(entry);
	shell->env[count + 1] = NULL;

	free(name);
}

int	builtin_cd(char **argv, t_shell *shell)
{
	char	*target;
	char	cwd[4096];
	char	*oldpwd = get_var_value("PWD", shell);  // shell->env içinden oku

	if (!oldpwd)
		oldpwd = getcwd(NULL, 0);  // fallback
	if (!oldpwd)
	{
		perror("getcwd");
		return 1;
	}

	if (!argv[1] || strcmp(argv[1], "~") == 0)
		target = get_var_value("HOME", shell);
	else if (strcmp(argv[1], "-") == 0)
	{
		target = get_var_value("OLDPWD", shell);
		if (!target || !*target)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			free(oldpwd);
			free(target);
			return 1;
		}
		printf("%s\n", target);  // bash uyumu
	}
	else
		target = strdup(argv[1]);

	if (chdir(target) != 0)
	{
		perror("cd");
		free(oldpwd);
		free(target);
		return 1;
	}

	// Güncel dizini oku
	if (getcwd(cwd, sizeof(cwd)))
	{
		char *line1 = malloc(strlen("OLDPWD=") + strlen(oldpwd) + 1);
		sprintf(line1, "OLDPWD=%s", oldpwd);
		update_env_var(line1, shell);
		free(line1);

		char *line2 = malloc(strlen("PWD=") + strlen(cwd) + 1);
		sprintf(line2, "PWD=%s", cwd);
		update_env_var(line2, shell);
		free(line2);
	}
	else
		perror("getcwd after cd");

	free(oldpwd);
	free(target);
	return 0;
}

int	builtin_exit(char **argv, t_shell *shell)
{
	(void)shell;

	printf("exit\n");

	if (!argv[1])
		exit(g_exit_status);

	if (!is_numeric(argv[1]))
	{
		fprintf(stderr, "exit: %s: numeric argument required\n", argv[1]);
		exit(255);
	}
	if (argv[2])
	{
		fprintf(stderr, "exit: too many arguments\n");
		g_exit_status = 1;
		return 1;
	}

	int status = atoi(argv[1]);
	exit(status & 0xFF);  // sadece son 8 bit
}

int builtin_echo(char **argv)
{
	int i = 1;
	int newline = 1;

	if (argv[1] && strcmp(argv[1], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");

	g_exit_status = 0;
	return 0;
}

int is_builtin(char *cmd)
{
	return (
		strcmp(cmd, "cd") == 0 ||
		strcmp(cmd, "exit") == 0 ||
		strcmp(cmd, "echo") == 0 ||
		strcmp(cmd, "pwd") == 0 ||
		strcmp(cmd, "env") == 0 ||
		strcmp(cmd, "export") == 0 ||   // ✅ BU SATIR VAR MI?
		strcmp(cmd, "unset") == 0
	);
}

int exec_builtin(char **argv, t_shell *shell)
{
	if (!argv || !argv[0])
		return 1;

	if (strcmp(argv[0], "cd") == 0)
		return builtin_cd(argv, shell);
	else if (strcmp(argv[0], "exit") == 0)
		return builtin_exit(argv, shell);
	else if (strcmp(argv[0], "echo") == 0)
		return builtin_echo(argv);
	else if (strcmp(argv[0], "pwd") == 0)
		return builtin_pwd(argv);
	else if (strcmp(argv[0], "env") == 0)
		return builtin_env(argv, shell->env);
	else if (strcmp(argv[0], "export") == 0)
		return builtin_export(argv, shell);
	else if (strcmp(argv[0], "unset") == 0)
		return builtin_unset(argv, shell);

	return 1;
}



int builtin_pwd(char **argv)
{
	(void)argv;
	char cwd[4096];
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		perror("pwd");
	g_exit_status = 0;
	return 0;
}

int builtin_env(char **argv, char **env)
{
	(void)argv;
	for (int i = 0; env[i]; i++)
		printf("%s\n", env[i]);
	g_exit_status = 0;
	return 0;
}

void	print_sorted_env(char **env)
{
	int count = 0;
	while (env[count])
		count++;

	char **sorted = malloc(sizeof(char *) * (count + 1));
	if (!sorted)
		return;
	for (int i = 0; i < count; i++)
		sorted[i] = strdup(env[i]);
	sorted[count] = NULL;

	// Bubble sort
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (strcmp(sorted[j], sorted[j + 1]) > 0)
			{
				char *tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
		}
	}

	// declare -x biçiminde yazdır
	for (int i = 0; i < count; i++)
	{
		char *eq = strchr(sorted[i], '=');
		if (eq)
		{
			*eq = '\0';
			printf("declare -x %s=\"%s\"\n", sorted[i], eq + 1);
			*eq = '='; // geri koy
		}
		else
			printf("declare -x %s\n", sorted[i]);

		free(sorted[i]);
	}
	free(sorted);
}

char *remove_quotes(const char *s)
{
	size_t len = strlen(s);
	char *res = malloc(len + 1);
	if (!res) return NULL;

	int j = 0;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] != '"' && s[i] != '\'')  // çift ve tek tırnakları atla
			res[j++] = s[i];
	}
	res[j] = '\0';
	return res;
}

int builtin_export(char **argv, t_shell *shell)
{
	int i = 1;

	if (!argv[1])
	{
		print_sorted_env(shell->env);
		g_exit_status = 0;
		return 0;
	}

	while (argv[i])
	{
		char *equal = strchr(argv[i], '=');
		char *name = NULL;

		if (equal)
			name = strndup(argv[i], equal - argv[i]);
		else
			name = strdup(argv[i]); // export VAR

		if (!name) return 1;

		// Sil: Aynı isimli varsa önce kaldır
		for (int j = 0; shell->env[j]; j++)
		{
			if (strncmp(shell->env[j], name, strlen(name)) == 0 &&
				shell->env[j][strlen(name)] == '=')
			{
				free(shell->env[j]);
				for (int k = j; shell->env[k]; k++)
					shell->env[k] = shell->env[k + 1];
				break;
			}
		}

		// Yeni satır oluştur
		char *new_entry = NULL;
		if (equal)
		{
			char *cleaned = remove_quotes(argv[i]);
			new_entry = strdup(cleaned);
			free(cleaned);
		}
		else
		{
			new_entry = malloc(strlen(name) + 2); // VAR=
			if (!new_entry) { free(name); return 1; }
			sprintf(new_entry, "%s=", name);
		}

		// Ekle
		int count = 0;
		while (shell->env[count])
			count++;

		shell->env = realloc(shell->env, sizeof(char *) * (count + 2));
		if (!shell->env) { free(name); free(new_entry); return 1; }
		shell->env[count] = new_entry;
		shell->env[count + 1] = NULL;

		free(name);
		i++;
	}
	g_exit_status = 0;
	return 0;
}

int builtin_unset(char **argv, t_shell *shell)
{
	int i = 1;
	while (argv[i])
	{
		int j = 0;
		while (shell->env[j])
		{
			if (strncmp(shell->env[j], argv[i], strlen(argv[i])) == 0 &&
				shell->env[j][strlen(argv[i])] == '=')
			{
				free(shell->env[j]);
				for (int k = j; shell->env[k]; k++)
					shell->env[k] = shell->env[k + 1];
				continue;
			}
			j++;
		}
		i++;
	}
	g_exit_status = 0;
	return 0;
}
