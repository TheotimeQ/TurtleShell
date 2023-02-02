/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:33:25 by tquere            #+#    #+#             */
/*   Updated: 2023/01/30 13:20:41 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <limits.h>

# include "struct.h"
# include "Exec/inc/exec.h"
# include "Parsing/includes/turtle_parsing.h"

extern int		g_cmd_running;

void	reset_the_terminal(t_minishell *sh);
void	termios_init(t_minishell *sh);
void	free_exit_sh(t_minishell *sh, int error_code);
void	free_to_exec(t_minishell *sh);

#endif
