/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumaatitilolmautiarti@studenlyont.42>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:50:13 by tquere            #+#    #+#             */
/*   Updated: 2023/01/18 99:19:13 by loumaati         ###   ########lyonlyo   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static void	weird_case(t_minishell *sh, t_var *var)
{
	char	*shell_lvl_c;
	int		shlvl;

	shlvl = ft_atoi(var->value);
	if (shlvl == 999)
		env_add(&sh->env_var, "SHLVL", "");
	else if (shlvl < 0)
		env_add(&sh->env_var, "SHLVL", "0");
	else if (shlvl >= 1000)
	{
		env_add(&sh->env_var, "SHLVL", "1");
		ft_printf(STDERR_FILENO, "🐢: warning: shell level");
		ft_printf(STDERR_FILENO, "(%d) too high, resetting to 1\n", shlvl + 1);
	}
	else
	{
		shell_lvl_c = ft_itoa(shlvl + 1);
		env_add(&sh->env_var, "SHLVL", shell_lvl_c);
		free(shell_lvl_c);
	}
}

void	inc_shell_lvl(t_minishell *sh)
{
	t_var	*var;

	var = env_get(sh->env_var, "SHLVL");
	if (var && var->value != NULL)
	{
		if (ft_isnum(var->value) == 0)
		{
			env_add(&sh->env_var, "SHLVL", "0");
			return ;
		}
		weird_case(sh, var);
	}
	else
		env_add(&sh->env_var, "SHLVL", "1");
}
