/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:30:11 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/16 07:34:03 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	needswapenv(char *delim)
{
	int	needswap;

	needswap = 1;
	if (ft_strchr(delim, '\'') != NULL || ft_strchr(delim, '\"') != NULL)
	{
		lowquotelevel(delim);
		needswap = 0;
	}
	return (needswap);
}
