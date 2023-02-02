/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:35:23 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/13 15:24:36 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static int	ck_start(char *line);
static int	ck_spe_spip(char *line);
static int	ck_spe_nl(char *line);

/**
 |  NOMENCLATURE USED TO PARSE
 |  pipe = [|]
 |  spe = [>][<][>>][<<]
 |  spip = spe + pipe = [>][<][>>][<<] + [|]
 |  nl = [\n] newline (it's the position of the '\0')
 |
 |  RULES : (whitespaces are ignored)
 |  1 - [start]->pipe	syntax error near unexpected token `|'
 |  2 - spe -> spip		syntax error near unexpected token `|' (the follower)
 |  3 - pipe -> spe		OK
 |  4 - spe -> [end]nl	syntax error near unexpected token `newline'
 */
int	check_syntax(char *line)
{
	if (!ck_start(line))
		return (0);
	if (!ck_spe_spip(line))
		return (0);
	if (!ck_spe_nl(line))
		return (0);
	if (pipe_terminated(line))
		return (syn_err("|"), 0);
	return (1);
}

// 1 - [start]->pipe	syntax error near unexpected token `|'
static int	ck_start(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			i++;
		else if (line[i] == '|')
			return (syn_err("|"), 0);
		else
			return (1);
	}
	return (1);
}

// 2 - spe -> spip		syntax error near unexpected token `|' (the follower)
static int	ck_spe_spip(char *line)
{
	int		i;
	char	inquotes;

	i = 0;
	inquotes = 0;
	while (line[i])
	{
		if (!inquotes && line[i] == '>')
		{
			if (line[i + 1] == '>')
				i++;
			if (!no_spip_after(line, i + 1))
				return (0);
		}
		else if (!inquotes && line[i] == '<')
		{
			if (line[i + 1] == '<')
				i++;
			if (!no_spip_after(line, i + 1))
				return (0);
		}
		ocquotes(line, &inquotes, i);
		i++;
	}
	return (1);
}

// 4 - spe -> [end]nl	syntax error near unexpected token `newline'
static int	ck_spe_nl(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0)
	{
		if (ft_isspace(line[i]))
			i--;
		else if (line[i] == '>' || line[i] == '<')
			return (syn_err("newline"), 0);
		else
			return (1);
	}
	return (1);
}
