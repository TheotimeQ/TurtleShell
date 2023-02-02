/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:53:05 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/12 13:21:40 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Alloue (avec malloc(3)) et retourne une chaine de caractere
	"fraiche" terminée par un '\0'. Chaque caractère de la chaine
	est initialise a '\0'. Si l'allocation echoue, la fonction renvoie
	NULL.
*/

#include "../inc/libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh_str;

	fresh_str = (char *)ft_calloc((size + 1), sizeof(*fresh_str));
	if (!fresh_str)
		return (NULL);
	return (fresh_str);
}
