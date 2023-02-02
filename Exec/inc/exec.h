/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:40:42 by tquere            #+#    #+#             */
/*   Updated: 2023/01/18 17:18:32 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

//Include lib
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

//Include header
# include "../../libft/inc/libft.h"
# include "../../struct.h"
# include "../../minishell.h"

# define ERROR 		1
# define SUCCESS 	0

//Fonction pour env_var / sh_var
t_var			*var_lst_last(t_var *lst);
void			var_add_back(t_var **lst, t_var *new);
void			env_init_var(t_minishell *sh);
void			env_sort(t_var **var);
void			env_print(t_var *var, t_cmd *cmd);
void			env_init(t_minishell *sh, t_var **var, char **envp);
void			env_add(t_var **var_list, char *name, char *value);
void			env_del(t_var **var, char *name);
int				env_exist(t_var *var, char *name);
void			env_cpy(t_var *var, t_var **var_cpy);
t_var			*env_get(t_var *var, char *name);
char			**env_to_str(t_var *var);
void			inc_shell_lvl(t_minishell *sh);
void			env_free(t_var **var_list);

//Fonction build_in
int				add_one_var(t_minishell *sh, char *name_value);
void			cpy_sort_print(t_minishell *sh, t_cmd *cmd);
void			exec_cd(t_minishell *sh, t_cmd *cmd, char **args);
void			exec_echo(t_cmd *cmd, char **args);
void			exec_env(t_minishell *sh, t_cmd *cmd, char **args);
void			exec_exit(t_minishell *sh, t_cmd *cmd, char **args);
void			exec_export(t_minishell *sh, t_cmd *cmd, char **args);
void			exec_pwd(t_cmd *cmd);
void			exec_unset(t_minishell *sh, t_cmd *cmd);

//Fonctions d'executions
int				exec(t_minishell *sh);
void			exec_cmds(t_minishell *sh);

//Fonctions pour les pipes
void			close_pipes(t_minishell *sh);
void			create_pipes(t_minishell *sh);
void			assign_pipe(t_minishell *sh);

//Fonction pour les paths
void			update_path(t_minishell *sh);
void			get_path(t_minishell *sh, char **envp);
char			*get_cmd_path(char **paths, char *cmd);

#endif
