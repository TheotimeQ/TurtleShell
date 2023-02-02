/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:34:03 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/14 13:40:20 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static int	m_getlen(char *raw, int start);
static void	strsteal(char *raw, char *filename, int start, int len);

char	*ext_filename(char *raw, int *start, int *len)
{
	char	*filename;

	while (ft_isspace(raw[*start]))
	{
		(*start)++;
	}
	*len = m_getlen(raw, *start);
	filename = ft_strnew(*len);
	if (!filename)
		return (NULL);
	strsteal(raw, filename, *start, *len);
	lowquotelevel(filename);
	return (filename);
}

int	pre_heredoc(t_cmd *cmd, char *raw, int start)
{
	char	*delim;
	int		delimlen;

	raw[start] = ' ';
	raw[start + 1] = ' ';
	start += 2;
	while (ft_isspace(raw[start]))
	{
		start++;
	}
	delimlen = m_getlen(raw, start);
	delim = ft_strnew(delimlen);
	if (!delim)
		return (0);
	strsteal(raw, delim, start, delimlen);
	ft_lstadd_back(&cmd->hdoc, ft_lstnew(delim));
	cmd->hdocwon = 1;
	return (1);
}

static int	m_getlen(char *raw, int start)
{
	int	i;

	i = 0;
	while (raw[i + start]
		&& !ft_isspace(raw[i + start]) && !ft_isinset(raw[i + start], "><"))
	{
		i++;
	}
	return (i);
}

// a ft_strlcpy which replace the src by spaces
static void	strsteal(char *raw, char *filename, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		filename[i] = raw[start + i];
		raw[start + i] = ' ';
		i++;
	}
}
