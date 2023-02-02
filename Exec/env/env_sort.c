/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:07:54 by tquere            #+#    #+#             */
/*   Updated: 2023/01/11 14:18:34 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static void	var_swap(t_var *a, t_var *b)
{
	char		*temp_name;
	char		*temp_value;

	temp_name = a->name;
	temp_value = a->value;
	a->name = b->name;
	a->value = b->value;
	b->name = temp_name;
	b->value = temp_value;
}

void	env_sort(t_var **var)
{
	int			swapped;
	t_var		*current;
	t_var		*next;

	if (*var == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *var;
		while (current->next != NULL)
		{
			next = current->next;
			if (ft_strcmp(current->name, next->name) > 0)
			{
				var_swap(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
	}
}
