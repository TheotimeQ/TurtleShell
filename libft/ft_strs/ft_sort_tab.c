/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:12 by tquere            #+#    #+#             */
/*   Updated: 2023/01/08 14:07:17 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_sort_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;
	int		len;

	i = 1;
	len = ft_count_tab(tab);
	while (i < len)
	{
		temp = tab[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(tab[j], temp) > 0)
		{
			tab[j + 1] = tab[j];
			j = j - 1;
		}
		tab[j + 1] = temp;
		i++;
	}
}
