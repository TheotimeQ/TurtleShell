/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:08 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		length_find;
	size_t		index_str;
	size_t		index_find;

	if (!haystack && len == 0)
		return (NULL);
	length_find = ft_strlen(needle);
	if (needle[0] == '\0')
		return (((char *)haystack));
	index_str = 0;
	while (haystack[index_str] && index_str < len)
	{
		index_find = 0;
		while (haystack[index_str + index_find] == needle[index_find]
			&& needle[index_find]
			&& haystack[index_str + index_find]
			&& index_str + index_find < len)
			index_find++;
		if (index_find == length_find)
			return (&((char *)haystack)[index_str]);
		index_str++;
	}
	return (NULL);
}
