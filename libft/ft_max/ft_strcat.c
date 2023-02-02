/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:13:57 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/11 14:44:21 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strcat() function append a copy of the null-terminated
	  string s2 to the end of the null-terminated string s1, then
     add a terminating ‘\0’.  The string s1 must have sufficient space to
     hold the result.
     The source and destination strings should not overlap, as the behavior
     is undefined.

RETURN VALUES
     The strcat() function return the pointer s1.
*/

#include "../inc/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
