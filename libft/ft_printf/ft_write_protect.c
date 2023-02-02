/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_protect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:17:31 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 14:25:18 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putchar_fd_printf(char c, t_flag *all_flag)
{	
	if (write(all_flag->fd, 0, 0) != 0)
	{
		all_flag->error = 1;
		return ;
	}
	write(all_flag->fd, &c, 1);
	all_flag->nb_caract += 1;
}

void	ft_putstr_fd_printf(char *str, t_flag *all_flag)
{
	size_t		len;

	if (!str)
	{
		write(all_flag->fd, "(null)", 6);
		all_flag->nb_caract += 6;
		return ;
	}
	len = ft_strlen(str);
	if (write(all_flag->fd, 0, 0) != 0)
	{
		all_flag->error = 1;
		return ;
	}
	write(all_flag->fd, str, len);
	all_flag->nb_caract += len;
}

void	ft_putnbr_fd_printf(long long int nb, t_flag *all_flag)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd_printf('-', all_flag);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd_printf(nb / 10, all_flag);
		ft_putnbr_fd_printf(nb % 10, all_flag);
	}
	else
		ft_putchar_fd_printf(nb + '0', all_flag);
}

static void	c_print(unsigned int nb, int len_base, char *base, t_flag *all_flag)
{
	if (nb > 0)
	{
		c_print(nb / len_base, len_base, base, all_flag);
		ft_putchar_fd_printf(base[(nb % len_base)], all_flag);
	}
}

void	ft_basprintf(unsigned int nb_long, char *base, t_flag *all_flag)
{
	int			len_base;

	len_base = ft_strlen(base);
	if (nb_long == 0)
	{
		write(all_flag->fd, &base[0], 1);
		all_flag->nb_caract += 1;
	}
	if (nb_long > 0)
	{
		c_print(nb_long, len_base, base, all_flag);
	}
}
