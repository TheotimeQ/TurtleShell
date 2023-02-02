/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:11:07 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/10 15:53:45 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 Prend en parametre l'adresse d'un pointeur dont la zone pointee
 doit etre liberee avec free(3), puis le pointeur est mis à NULL.
 */

#include "../inc/libft.h"

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
