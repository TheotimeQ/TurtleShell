/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:40:15 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/10 15:52:45 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	  white-space character test
DESCRIPTION
     The isspace() function tests for the white-space characters.
	  For any locale, this includes the following standard characters:
     \t \n \v \f \r ' ' -> (espace)

     In the "C" locale, isspace() successful test is limited to these characters
     only.  The value of the argument must be representable as an unsigned
	  char or the value of EOF.
RETURN VALUES
     The isspace() function returns zero if the character tests false and returns
     non-zero if the character tests true.
*/

#include "../inc/libft.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}
