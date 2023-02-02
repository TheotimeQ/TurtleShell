/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:56 by tquere            #+#    #+#             */
/*   Updated: 2023/01/30 13:20:52 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_cmd_running;

void	reset_the_terminal(t_minishell *sh)
{
	struct termios		termios_new;
	int					rc;

	rc = tcgetattr(0, sh->tty);
	if (rc)
	{
		perror("tcgetattr");
		exit(1);
	}
	termios_new = *sh->tty;
	termios_new.c_lflag |= ECHOCTL;
	rc = tcsetattr(0, 0, &termios_new);
	if (rc)
	{
		perror("tcsetattr");
		exit(1);
	}
}

static t_minishell	*init_minishell(void)
{
	t_minishell	*sh;

	sh = malloc(sizeof(t_minishell));
	if (sh == NULL)
		exit(1);
	sh->pipes = NULL;
	sh->path = NULL;
	sh->env_var = NULL;
	sh->env_var_cpy = NULL;
	sh->sh_var = NULL;
	sh->to_exec = NULL;
	sh->last_ret = SUCCESS;
	return (sh);
}

void	termios_init(t_minishell *sh)
{
	struct termios		termios_new;
	int					rc;

	rc = tcgetattr(0, sh->tty);
	if (rc)
	{
		perror("tcgetattr");
		exit(1);
	}
	termios_new = *sh->tty;
	termios_new.c_lflag &= ~ECHOCTL;
	rc = tcsetattr(0, 0, &termios_new);
	if (rc)
	{
		perror("tcsetattr");
		exit(1);
	}
}

int	main(int ac, char **av, char **envp)
{	
	struct termios		termios_save;
	t_minishell			*sh;

	(void)av;
	if (ac != 1)
		return (err_man(USAGE), 1);
	sh = init_minishell();
	sh->tty = &termios_save;
	termios_init(sh);
	get_path(sh, envp);
	env_init(sh, &sh->env_var, envp);
	inc_shell_lvl(sh);
	env_init_var(sh);
	prompt_loop(sh);
	free_exit_sh(sh, 0);
}
