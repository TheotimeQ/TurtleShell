/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:26:37 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	elem = ft_lstnew(f(lst->content));
	if (elem == NULL)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	new_list = elem;
	lst = lst->next;
	while (lst != NULL)
	{	
		elem = ft_lstnew(f(lst->content));
		if (elem == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_list, elem);
	}
	return (new_list);
}
