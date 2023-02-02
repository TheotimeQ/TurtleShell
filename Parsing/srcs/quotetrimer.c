/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotetrimer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:14:15 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/14 13:39:09 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static void	shift_backward(int *index, char *str, char *inquotes);

void	quotetrimer(t_sh *sh)
{
	int	i;
	int	j;

	i = 0;
	while (i < sh->to_exec->nb_cmd)
	{
		j = 0;
		if (sh->to_exec->all_cmd[i] != NULL)
		{
			while (j < sh->to_exec->all_cmd[i]->ac)
			{
				lowquotelevel(sh->to_exec->all_cmd[i]->av[j]);
				j++;
			}
		}
		i++;
	}
}

void	lowquotelevel(char *token)
{
	char	inquotes;
	int		i;

	i = 0;
	inquotes = 0;
	while (token[i])
	{
		if (!inquotes && (token[i] == '\'' || token[i] == '\"'))
			shift_backward(&i, token, &inquotes);
		else if (inquotes && token[i] == inquotes)
		{
			shift_backward(&i, token, &inquotes);
			inquotes = 0;
		}
		i++;
	}
}

// use memeove to shift a string of one position backward, erasing quote
static void	shift_backward(int *index, char *str, char *inquotes)
{
	size_t	rmdlen;

	*inquotes = str[*index];
	rmdlen = ft_strlen(str + *index + 1);
	ft_memmove(str + *index, str + (*index) + 1, rmdlen);
	str[ft_strlen(str) - 1] = '\0';
	(*index)--;
}
