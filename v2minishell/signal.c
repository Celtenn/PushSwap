#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);  // Yeni satır
	rl_on_new_line();    // Readline'a yeni satır olduğunu bildir
	rl_replace_line("", 0);  // Girdiyi sil
	rl_redisplay();      // Prompt'u yeniden yaz
}

void	setup_signals(void)
{
	signal(SIGINT, handle_sigint);   // Ctrl-C
	signal(SIGQUIT, SIG_IGN);        // Ctrl-\ yoksay
}
