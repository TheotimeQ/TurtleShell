/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:52:04 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 10:06:36 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static void	print_dec(t_var *lst, t_cmd *cmd)
{
	ft_printf(cmd->output_fd, "declare -x ");
	ft_printf(cmd->output_fd, "%s", lst->name);
	if (lst->value)
	{
		ft_printf(cmd->output_fd, "=");
		ft_printf(cmd->output_fd, "%c", '"');
		ft_printf(cmd->output_fd, "%s", lst->value);
		ft_printf(cmd->output_fd, "%c\n", '"');
	}
	else
		ft_printf(cmd->output_fd, "\n");
}

static void	env_print_dec(t_var *var, t_cmd *cmd)
{
	if (var == NULL)
		return ;
	print_dec(var, cmd);
	while (var->next != NULL)
	{	
		var = var->next;
		print_dec(var, cmd);
	}
	return ;
}

void	cpy_sort_print(t_minishell *sh, t_cmd *cmd)
{	
	env_cpy(sh->env_var, &sh->env_var_cpy);
	env_sort(&sh->env_var_cpy);
	env_print_dec(sh->env_var_cpy, cmd);
	env_free(&sh->env_var_cpy);
}

static void	add_if(t_minishell *sh, char *name, char *value)
{	
	t_var	*var;

	var = env_get(sh->env_var, name);
	if (var && value == NULL)
		return ;
	env_add(&sh->env_var, name, value);
}

int	add_one_var(t_minishell *sh, char *name_value)
{
	char	*name;
	char	*value;
	char	**var_split;

	if (name_value[0] == '=')
	{
		ft_printf(2, "🐢: export: `%s': not a valid identifier", name_value);
		return (1);
	}
	var_split = ft_split(name_value, '=');
	if (var_split == NULL)
		return (1);
	name = var_split[0];
	if (var_split && name)
	{
		if (ft_strlen(name_value) >= ft_strlen(name) + 1)
			value = name_value + ft_strlen(name) + 1;
		else
			value = NULL;
		add_if(sh, name, value);
	}
	ft_free_tab(var_split);
	return (0);
}
