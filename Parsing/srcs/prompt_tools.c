/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:44:07 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/13 15:18:19 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

int	no_spip_after(char *line, int start)
{
	while (line[start])
	{
		if (ft_isspace(line[start]))
			start++;
		else if (line[start] == '|')
			return (syn_err("|"), 0);
		else if (line[start] == '>' && line[start + 1] == '>')
			return (syn_err(">>"), 0);
		else if (line[start] == '<' && line[start + 1] == '<')
			return (syn_err("<<"), 0);
		else if (line[start] == '>')
			return (syn_err(">"), 0);
		else if (line[start] == '<')
			return (syn_err("<"), 0);
		else
			return (1);
	}
	return (1);
}

// [!] here inquotes is a single character adress, not a character string
void	ocquotes(char *line, char *inquotes, int index)
{
	if (!(*inquotes) && (line[index] == '\'' || line[index] == '\"'))
		*inquotes = line[index];
	else if ((*inquotes) == '\'' && line[index] == '\'')
		*inquotes = 0;
	else if ((*inquotes) == '\"' && line[index] == '\"')
		*inquotes = 0;
	else
		return ;
}

// tells if there is a '|' at end, with or without whitespaces
int	pipe_terminated(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0)
	{
		if (ft_isspace(line[i]))
			i--;
		else if (line[i] == '|')
			return (1);
		else
			return (0);
	}
	return (0);
}
