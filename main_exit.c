/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:55:56 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 12:13:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	del_one_hdoc(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->content);
	free(lst);
}

static void	h_doc_free(t_list **lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		del_one_hdoc(*lst);
		*lst = tmp;
	}
	lst = NULL;
}

static void	ft_cmd_av(t_cmd *cmd)
{
	int	index;

	if (cmd->av == NULL)
		return ;
	index = 0;
	while (cmd->av[index])
	{
		free(cmd->av[index]);
		index++;
	}
	free(cmd->av);
	cmd->av = NULL;
}

void	free_to_exec(t_minishell *sh)
{
	int		i;

	i = -1;
	if (!sh || !sh->to_exec)
		return ;
	if (!sh->to_exec->all_cmd)
	{
		free(sh->to_exec);
		sh->to_exec = NULL;
		return ;
	}
	while (++i < sh->to_exec->nb_cmd)
	{	
		if (sh->to_exec->all_cmd[i])
		{
			if (sh->to_exec->all_cmd[i]->hdoc)
				h_doc_free(&sh->to_exec->all_cmd[i]->hdoc);
			ft_cmd_av(sh->to_exec->all_cmd[i]);
			free(sh->to_exec->all_cmd[i]);
		}
	}
	free(sh->to_exec->all_cmd);
	sh->to_exec->all_cmd = NULL;
	free(sh->to_exec);
	sh->to_exec = NULL;
}

void	free_exit_sh(t_minishell *sh, int error_code)
{	
	reset_the_terminal(sh);
	ft_free_tab(sh->path);
	if (sh->pipes)
		free(sh->pipes);
	env_free(&sh->env_var);
	env_free(&sh->env_var_cpy);
	env_free(&sh->sh_var);
	free_to_exec(sh);
	free(sh);
	exit(error_code);
}
