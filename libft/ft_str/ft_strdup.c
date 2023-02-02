/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:34:39 by tquere            #+#    #+#             */
/*   Updated: 2023/01/10 13:44:57 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	int		len_src;
	char	*dest;
	int		i;

	if (!s1)
		return (NULL);
	len_src = ft_strlen(s1);
	dest = malloc(sizeof(char) * len_src + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{	
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
