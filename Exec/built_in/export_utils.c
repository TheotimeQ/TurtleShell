/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:04:31 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 09:59:42 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static int	check_valid(char **args)
{	
	int		i;
	char	**var_split;

	i = 1;
	while (i < ft_count_tab(args))
	{	
		var_split = ft_split(args[i], '=');
		if (var_split == NULL)
			return (0);
		if (var_split[0] == NULL)
			return (0);
		if ((!ft_isalpha(var_split[0][0]))
			|| ft_isalphas_nums(var_split[0]) == 0)
		{
			ft_printf(2, "🐢: export: `%s': not a valid identifier\n",
				var_split[0]);
			ft_free_tab(var_split);
			return (1);
		}
		ft_free_tab(var_split);
		i++;
	}
	return (0);
}

void	exec_export(t_minishell *sh, t_cmd *cmd, char **args)
{
	int		i;

	if (ft_count_tab(args) == 1)
	{	
		cmd->ret = 0;
		cpy_sort_print(sh, cmd);
		return ;
	}
	cmd->ret = check_valid(args);
	if (cmd->ret != 0)
		return ;
	i = 1;
	while (i < ft_count_tab(args))
	{
		if (add_one_var(sh, args[i++]) == 1)
		{
			cmd->ret = 1;
			return ;
		}
	}
	cmd->ret = 0;
	return ;
}
