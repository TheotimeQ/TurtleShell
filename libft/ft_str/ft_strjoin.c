/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:20:56 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			index;
	size_t			len_s1;
	size_t			len_s2;
	char			*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * ((len_s1 + len_s2) + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index < len_s1 && s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (index - len_s1 < len_s2 && s2[index - len_s1])
	{
		str[index] = s2[index - len_s1];
		index++;
	}
	str[index] = '\0';
	return (str);
}
