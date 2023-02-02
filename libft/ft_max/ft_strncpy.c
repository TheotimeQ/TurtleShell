/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:26:29 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/11 14:40:56 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
     The strncpy() function copy at most len characters from
     src into dst.  If src is less than len characters long, the remainder
     of dst is filled with ‘\0’ characters.
	  Otherwise, dst is not terminated.
     The source and destination strings should not overlap, as the behavior
     is undefined.
RETURN VALUES
     The strncpy() function return dst.
*/

#include "../inc/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		fill_zero;

	i = 0;
	fill_zero = 0;
	while (i < len)
	{
		if (fill_zero)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		if (!fill_zero && src[i] == '\0')
			fill_zero = 1;
		i++;
	}
	return (dst);
}
