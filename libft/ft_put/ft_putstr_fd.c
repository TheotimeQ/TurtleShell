/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:18 by tquere            #+#    #+#             */
/*   Updated: 2023/01/10 15:48:16 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int		index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
	{
		write(fd, &s[index++], 1);
	}
}
