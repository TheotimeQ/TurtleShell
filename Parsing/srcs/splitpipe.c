/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitpipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:04:33 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/13 10:07:40 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static int	get_cmdlen(char *prompt, int start);

// Go through the pipeline to divide it into a char **interpipe
char	**splitpipe(char *prompt, int nb_cmd)
{
	char	**splitpipe;
	int		cmd_index;
	int		cmd_len;
	int		i;

	splitpipe = ft_strsnew(nb_cmd);
	if (!splitpipe)
		return (NULL);
	i = 0;
	cmd_index = 0;
	while (prompt[i])
	{
		if (prompt[i] != '|')
		{
			cmd_len = get_cmdlen(prompt, i);
			splitpipe[cmd_index] = ft_substr(prompt, i, cmd_len);
			if (!splitpipe)
				return (ft_strsdel(&splitpipe), NULL);
			cmd_index += 1;
			i += cmd_len;
		}
		else
			i++;
	}
	return (splitpipe);
}

static int	get_cmdlen(char *prompt, int start)
{
	int		i;
	int		cmd_len;
	char	inquotes;

	i = start;
	cmd_len = 0;
	inquotes = 0;
	while (prompt[i])
	{
		if (!inquotes && prompt[i] == '|')
			return (cmd_len);
		else if (!inquotes && (prompt[i] == '\'' || prompt[i] == '\"'))
			inquotes = prompt[i];
		else if (inquotes == '\'' && prompt[i] == '\'')
			inquotes = 0;
		else if (inquotes == '\"' && prompt[i] == '\"')
			inquotes = 0;
		i++;
		cmd_len++;
	}
	return (cmd_len);
}

int	count_cmds(char *prompt)
{
	int		i;
	int		counter;
	char	inquotes;

	i = 0;
	counter = 1;
	inquotes = 0;
	while (prompt[i])
	{
		if (!inquotes && prompt[i] == '|')
			counter += 1;
		else if (!inquotes && (prompt[i] == '\'' || prompt[i] == '\"'))
			inquotes = prompt[i];
		else if (inquotes == '\'' && prompt[i] == '\'')
			inquotes = 0;
		else if (inquotes == '\"' && prompt[i] == '\"')
			inquotes = 0;
		i++;
	}
	return (counter);
}
