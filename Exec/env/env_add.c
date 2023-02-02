/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:40:56 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 10:33:34 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static void	add_one(t_var **var_list, t_var *new_var, char *name, char *value)
{
	new_var->name = ft_strdup(name);
	if (value)
		new_var->value = ft_strdup(value);
	else
		new_var->value = NULL;
	new_var->next = NULL;
	var_add_back(var_list, new_var);
}

void	env_add(t_var **var_list, char *name, char *value)
{	
	t_var		*new_var;
	t_var		*var;

	var = env_get(*var_list, name);
	if (var != NULL)
	{
		var = env_get(*var_list, name);
		free(var->value);
		if (value)
			var->value = ft_strdup(value);
		else
			var->value = NULL;
	}
	else
	{
		new_var = malloc(sizeof(t_var));
		if (new_var == NULL)
			return ;
		add_one(var_list, new_var, name, value);
	}
}
