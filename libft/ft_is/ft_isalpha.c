/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:16:29 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 08:59:25 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_')
		return (1);
	return (0);
}

int	ft_isalphas(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (ft_isalpha(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isalphas_nums(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (ft_isalpha(str[i]) == 0 && !('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

//_ valide