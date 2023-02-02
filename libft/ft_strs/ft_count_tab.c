/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:12 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 16:54:13 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_count_tab(char **tab)
{
	int	index;

	if (tab == NULL)
		return (0);
	index = 0;
	while (tab[index])
		index++;
	return (index);
}
