/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:51:00 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/12 13:22:51 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocate and fill with zeros a char **
	( ~ an array of char *)
*/

#include "../inc/libft.h"

char	**ft_strsnew(size_t size)
{
	char	**strs;

	strs = (char **)ft_calloc((size + 1), sizeof(*strs));
	return (strs);
}
