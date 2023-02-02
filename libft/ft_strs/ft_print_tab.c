/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:12 by tquere            #+#    #+#             */
/*   Updated: 2023/01/10 11:34:24 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_print_tab(char **tab)
{
	int	index;

	if (tab == NULL)
		return ;
	index = 0;
	while (tab[index])
	{
		ft_printf(STDOUT_FILENO, "%s\n", tab[index]);
		index++;
	}
}
