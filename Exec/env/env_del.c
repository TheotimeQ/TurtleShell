/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:40:56 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 09:17:26 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static void	ft_var_del(t_var *lst)
{	
	if (!lst)
		return ;
	free(lst->name);
	free(lst->value);
	free(lst);
}

void	env_free(t_var **lst)
{
	t_var	*tmp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_var_del(*lst);
		*lst = tmp;
	}
	lst = NULL;
}

void	env_del(t_var **var, char *name)
{	
	t_var	*last_var;
	t_var	*cur_var;

	if (var == NULL)
		return ;
	cur_var = *var;
	if (ft_strcmp(cur_var->name, name) == 0)
	{	
		ft_var_del(cur_var);
		*var = cur_var->next;
		return ;
	}
	last_var = cur_var;
	cur_var = last_var->next;
	while (cur_var != NULL)
	{
		if (ft_strcmp(cur_var->name, name) == 0)
		{	
			last_var->next = cur_var->next;
			ft_var_del(cur_var);
			return ;
		}
		last_var = cur_var;
		cur_var = last_var->next;
	}
}
