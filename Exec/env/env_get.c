/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:40:56 by tquere            #+#    #+#             */
/*   Updated: 2023/01/11 16:56:16 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

t_var	*env_get(t_var *lst, char *name)
{
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (ft_strcmp(lst->name, name) == 0)
			return (lst);
		lst = (lst)->next;
	}
	return (NULL);
}
