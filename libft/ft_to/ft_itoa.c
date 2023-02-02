/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:36 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	len_int(long int n)
{
	int	index;

	index = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

static int	get_char(long int nbr, int len_nb, char *char_nb)
{	
	int			index;

	index = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len_nb += 1;
		char_nb[0] = '-';
	}
	if (nbr == 0)
		char_nb[0] = '0';
	while (nbr > 0)
	{
		char_nb[len_nb - index++ - 1] = "0123456789"[nbr % 10];
		nbr /= 10;
	}
	return (len_nb);
}

char	*ft_itoa(int n)
{
	char		*char_nb;
	int			len_nb;
	long int	nbr;

	nbr = n;
	len_nb = len_int(nbr);
	if (nbr < 0)
		char_nb = malloc(sizeof(char) * (len_nb + 2));
	else
		char_nb = malloc(sizeof(char) * (len_nb + 1));
	if (char_nb == NULL)
		return (NULL);
	len_nb = get_char(nbr, len_nb, char_nb);
	char_nb[len_nb] = '\0';
	return (char_nb);
}
