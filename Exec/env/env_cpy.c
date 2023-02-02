/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:07:54 by tquere            #+#    #+#             */
/*   Updated: 2023/01/19 09:53:22 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

void	env_cpy(t_var *env_var, t_var **env_var_cpy)
{	
	t_var		*new_var;

	if (env_var == NULL)
		return ;
	new_var = malloc(sizeof(t_var));
	if (new_var == NULL)
		return ;
	new_var->name = ft_strdup(env_var->name);
	new_var->value = ft_strdup(env_var->value);
	new_var->next = NULL;
	var_add_back(env_var_cpy, new_var);
	while (env_var->next != NULL)
	{	
		env_var = env_var->next;
		new_var = malloc(sizeof(t_var));
		if (new_var == NULL)
			return ;
		new_var->name = ft_strdup(env_var->name);
		new_var->value = ft_strdup(env_var->value);
		new_var->next = NULL;
		var_add_back(env_var_cpy, new_var);
	}
}
