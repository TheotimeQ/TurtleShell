/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_inpipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:13:59 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/14 09:47:52 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static t_cmd	*init_cmd(t_sh *sh, char **raw_inpipe);

/**
 |  Extract the content of each interpipe as a char **av representing
 |  a command. In this steps, the environment variables are swapped
 |  then the quotes are trim to one lower level. redirections are done before
 */
int	ext_inpipe(t_sh *sh, char **raw_inpipe)
{
	int		i;

	sh->to_exec->all_cmd = malloc(sizeof(t_cmd *) * (sh->to_exec->nb_cmd + 1));
	if (!sh->to_exec->all_cmd)
		return (0);
	sh->to_exec->all_cmd[sh->to_exec->nb_cmd] = NULL;
	i = 0;
	while (i < sh->to_exec->nb_cmd)
	{
		sh->to_exec->all_cmd[i] = init_cmd(sh, &raw_inpipe[i]);
		i++;
	}
	quotetrimer(sh);
	return (1);
}

/**
 |  initialize each (t_cmd *cmd) command,
 |  make required redirections
 */
static t_cmd	*init_cmd(t_sh *sh, char **raw_inpipe)
{
	char	**tokens;
	int		tsize;
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->input_fd = 0;
	cmd->output_fd = 1;
	cmd->ac = 0;
	cmd->av = NULL;
	cmd->hdoc = NULL;
	cmd->hdocwon = 0;
	if (!redi_manager(cmd, *raw_inpipe))
		return (free(cmd), NULL);
	swap_env(sh, raw_inpipe);
	tokens = splitinpipe(*raw_inpipe, &tsize);
	if (!tokens)
		return (free(cmd), NULL);
	cmd->av = tokens;
	cmd->ac = tsize;
	return (cmd);
}
