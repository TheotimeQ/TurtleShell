/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:52:07 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 09:23:42 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static int	check_valid(char **args)
{	
	int		i;

	i = 1;
	while (i < ft_count_tab(args))
	{
		if (!ft_isalpha(args[i][0]) || ft_isalphas_nums(args[i]) == 0)
		{
			ft_printf(2, "🐢: unset: `%s': not a valid identifier\n", args[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	exec_unset(t_minishell *sh, t_cmd *cmd)
{
	int		i;

	check_valid(cmd->av);
	i = 1;
	while (i < ft_count_tab(cmd->av))
	{	
		env_del(&sh->env_var, cmd->av[i]);
		i++;
	}
	cmd->ret = 0;
}
