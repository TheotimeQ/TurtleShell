/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:31 by tquere            #+#    #+#             */
/*   Updated: 2023/01/09 15:21:41 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	all_test(const char *str, va_list arg, t_flag *all_flag)
{	
	char		*lhex;
	char		*hhex;

	lhex = "0123456789abcdef";
	hhex = "0123456789ABCDEF";
	if (str[all_flag->index] == 'c')
		ft_putchar_fd_printf(va_arg(arg, int), all_flag);
	else if (str[all_flag->index] == 's')
		ft_putstr_fd_printf(va_arg(arg, char *), all_flag);
	else if (str[all_flag->index] == 'p')
		ft_uprintf(va_arg(arg, unsigned long int), lhex, all_flag);
	else if (str[all_flag->index] == 'd' || str[all_flag->index] == 'i')
		ft_putnbr_fd_printf(va_arg(arg, int), all_flag);
	else if (str[all_flag->index] == 'u')
		ft_putnbr_fd_printf(va_arg(arg, unsigned int), all_flag);
	else if (str[all_flag->index] == 'x')
		ft_basprintf(va_arg(arg, unsigned int), lhex, all_flag);
	else if (str[all_flag->index] == 'X')
		ft_basprintf(va_arg(arg, unsigned int), hhex, all_flag);
	else if (str[all_flag->index] == '%')
		ft_putchar_fd_printf('%', all_flag);
	else if (str[all_flag->index])
		ft_putchar_fd_printf(str[all_flag->index], all_flag);
}

static void	print_str(const char *str, va_list arg, t_flag *all_flag)
{	
	while (str[all_flag->index])
	{	
		if (str[all_flag->index] != '%')
			ft_putchar_fd_printf(str[all_flag->index], all_flag);
		else
		{	
			all_flag->index++;
			all_test(str, arg, all_flag);
		}
		if (str[all_flag->index])
			all_flag->index++;
	}
}

int	ft_printf(int fd, const char *str, ...)
{	
	va_list		arg;
	t_flag		all_flag;

	if (write(1, 0, 0) != 0)
		return (-1);
	all_flag.index = 0;
	all_flag.nb_caract = 0;
	all_flag.fd = fd;
	all_flag.error = 0;
	va_start(arg, str);
	print_str(str, arg, &all_flag);
	va_end(arg);
	if (all_flag.error == 1)
		return (-1);
	return (all_flag.nb_caract);
}
