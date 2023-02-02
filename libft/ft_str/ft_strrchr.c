/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:10 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{	
	int		index_str;
	char	*ptr;
	char	c_char;

	c_char = c;
	ptr = NULL;
	index_str = 0;
	while (s[index_str])
	{
		if (s[index_str] == c_char)
			ptr = &((char *)s)[index_str];
		index_str++;
	}
	if (s[index_str] == c_char)
		ptr = &((char *)s)[index_str];
	return (ptr);
}
