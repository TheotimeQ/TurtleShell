/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:32:49 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 12:18:47 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft/inc/libft.h"
# include <termios.h>

typedef struct termios	t_term;

typedef struct s_var
{
	char	*name;
	char	*value;
	void	*next;

}	t_var;

typedef struct s_cmd
{
	int			input_fd;
	int			output_fd;
	int			ac;
	char		**av;
	int			ret;
	int			pid;
	t_list		*hdoc;
	int			hdocwon;

}	t_cmd;

typedef struct s_to_exec
{
	int			nb_cmd;
	t_cmd		**all_cmd;

}	t_to_exec;

typedef struct s_minishell
{
	char		**path;
	int			*pipes;
	t_var		*env_var;
	t_var		*env_var_cpy;
	t_var		*sh_var;
	t_to_exec	*to_exec;
	int			last_ret;
	t_term		*tty;
	int			forked;
	t_cmd		*cmd;

}	t_minishell;

typedef t_minishell		t_sh;

#endif
