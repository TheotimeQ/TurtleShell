/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:04:33 by tquere            #+#    #+#             */
/*   Updated: 2023/01/13 14:21:00 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

t_var	*var_lst_last(t_var *lst)
{	
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{	
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	var_add_back(t_var **lst, t_var *new)
{	
	if (*lst == NULL)
	{	
		*lst = new;
		return ;
	}
	var_lst_last(*lst)->next = new;
}
