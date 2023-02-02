/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:11:41 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/13 16:49:48 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static void	ft_puterrnl(char *err_msg);

// Display a message error in stderror followed by a newline.
void	err_man(t_err error)
{
	if (error == USAGE)
		ft_puterrnl("Error : turle terminal doesn't allow arguments");
	else if (error == PIPESYN)
		ft_puterrnl("🐢: syntax error near unexpected token `|'");
	else if (error == MALLOC)
		ft_puterrnl("Error occured while allocate memory");
	else
		ft_puterrnl("Error");
}

void	file_err(const char *filename)
{
	ft_putstr_fd("🐢: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	syn_err(const char *token)
{
	ft_putstr_fd("🐢: ", 2);
	ft_putstr_fd("syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("\'\n", 2);
}

static void	ft_puterrnl(char *err_msg)
{
	int	i;

	i = 0;
	while (err_msg[i])
	{
		write(2, &err_msg[i], 1);
		i++;
	}
	write (2, "\n", 1);
}
