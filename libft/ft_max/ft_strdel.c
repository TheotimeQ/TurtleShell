/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 09:42:53 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/10 15:52:51 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Prend en parametre l'adresse d'une chaine de caracteres qui
	doit etre liberee avec free(3) et son pointeur mis à NULL.
*/

#include "../inc/libft.h"

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
