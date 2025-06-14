#include "minishell.h"
#include "parser.h"
#include "lexer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern int g_exit_status; // $? için global değişken

char *get_var_value(const char *name, t_shell *shell)
{
	if (!shell || !shell->env)
		return strdup("");

	if (strcmp(name, "?") == 0)
	{
		char *res = malloc(12);
		if (res)
			sprintf(res, "%d", g_exit_status);
		return res;
	}

	for (int i = 0; shell->env[i]; i++)
	{
		if (strncmp(shell->env[i], name, strlen(name)) == 0
			&& shell->env[i][strlen(name)] == '=')
			return strdup(shell->env[i] + strlen(name) + 1);
	}
	return strdup("");
}

char *expand_variables(const char *input, t_shell *shell)
{
	if (!strchr(input, '$'))
		return strdup(input);  // hiçbir şey genişletilmeden döner

	char *result = calloc(1, 1);
	int i = 0;

	while (input[i])
	{
		if (input[i] == '$' && input[i + 1])
		{
			i++;
			if (input[i] == '?')  // ✅ ÖZEL DURUM
			{
				char *value = get_var_value("?", shell);
				if (!value) value = strdup("");

				size_t new_len = strlen(result) + strlen(value) + 1;
				char *temp = realloc(result, new_len);
				if (!temp) {
					free(value); free(result);
					return NULL;
				}
				result = temp;
				strcat(result, value);
				free(value);
				i++;  // '?' karakterini geç
			}
			else if (isalnum(input[i]) || input[i] == '_')  // normal $VAR
			{
				int start = i;
				while (isalnum(input[i]) || input[i] == '_')
					i++;
				char *varname = strndup(&input[start], i - start);
				if (!varname) break;

				char *value = get_var_value(varname, shell);
				if (!value) value = strdup("");

				size_t new_len = strlen(result) + strlen(value) + 1;
				char *temp = realloc(result, new_len);
				if (!temp) {
					free(varname); free(value); free(result);
					return NULL;
				}
				result = temp;
				strcat(result, value);

				free(varname);
				free(value);
			}
			else
			{
				// $ ardından geçersiz karakter geldi → olduğu gibi al
				char temp[3] = {'$', input[i], '\0'};
				size_t new_len = strlen(result) + 3;
				char *temp_result = realloc(result, new_len);
				if (!temp_result) {
					free(result);
					return NULL;
				}
				result = temp_result;
				strcat(result, temp);
				i++;
			}
		}
		else
		{
			char temp[2] = { input[i], '\0' };
			size_t new_len = strlen(result) + 2;
			char *new_result = realloc(result, new_len);
			if (!new_result) {
				free(result);
				return NULL;
			}
			result = new_result;
			strcat(result, temp);
			i++;
		}
	}
	return result;
}
