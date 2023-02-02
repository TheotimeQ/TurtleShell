/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turtle_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:22:41 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/18 17:17:43 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURTLE_PARSING_H

# define TURTLE_PARSING_H

# include "../../struct.h"
# include "../../minishell.h"
# include "../../libft/inc/libft.h"

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

typedef enum e_err {
	USAGE,
	PIPESYN,
	MALLOC
}			t_err;

// prompt - readline - check syntax
void	prompt_loop(t_sh *sh);
int		check_syntax(char *line);
int		no_spip_after(char *line, int start);
void	ocquotes(char *line, char *inquotes, int index);
int		pipe_terminated(char *line);
char	*pipe_ter_seq(char *line);

// error management
void	err_man(t_err error);
void	file_err(const char *filename);
void	syn_err(const char *token);

// parsing steps
int		proc_parsing(t_sh *sh, char *prompt);

// pipeline
int		count_cmds(char *prompt);
char	**splitpipe(char *prompt, int nb_cmd);

// interpipes splittokens
int		ext_inpipe(t_sh *sh, char **raw_inpipe);
char	**splitinpipe(char *s, int *ssize);

// redirections
int		redi_manager(t_cmd *cmd, char *raw);
char	*ext_filename(char *raw, int *start, int *len);
int		redirection_hub(t_cmd *cmd, char *raw, int i, char inquotes);

// heredoc
int		pre_heredoc(t_cmd *cmd, char *raw, int start);
void	here_docs(t_minishell *sh);

// environnment var
void	swap_env(t_sh *sh, char **raw_inpipe);
void	swap_env_doc(t_sh *sh, char **raw_inpipe);
void	swap_dollar(t_sh *sh, char **token, int dollpos);
int		needswapenv(char *delim);

// quote trimer
void	quotetrimer(t_sh *sh);
void	lowquotelevel(char *token);

//signal
int		catch_signal(struct sigaction *action);
int		catch_signal_hdoc(struct sigaction *action);

#endif
