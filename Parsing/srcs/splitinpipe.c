/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitinpipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 07:04:24 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/13 11:22:08 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static size_t	get_token_len(char *s, unsigned int start);
static size_t	token_count(char *s);
static int		go_through_tokens(char c, int *into_token, char *inquotes);

/**
 |  @brief a ft_splitset customized to not split within quotes or double quotes
 |
 */
char	**splitinpipe(char *s, int *ssize)
{
	char			**split;
	unsigned int	i;
	size_t			tokenlen;
	unsigned int	token_index;

	split = ft_strsnew(token_count(s));
	if (!split)
		return (NULL);
	i = -1;
	token_index = 0;
	while (s[++i])
	{
		if (!ft_isspace(s[i]))
		{
			tokenlen = get_token_len(s, i);
			split[token_index] = ft_substr(s, i, tokenlen);
			if (!split[token_index])
				return (ft_strsdel(&split), NULL);
			token_index += 1;
			i += (unsigned int)tokenlen - 1;
		}
	}
	*ssize = token_index;
	return (split);
}

static size_t	get_token_len(char *s, unsigned int start)
{
	size_t	tokenlen;
	char	inquotes;

	tokenlen = 0;
	inquotes = 0;
	while (s[start] && (!ft_isspace(s[start])
			|| inquotes || ft_isinset(s[start], "\'\"")))
	{
		if (!inquotes && (s[start] == '\'' || s[start] == '\"'))
			inquotes = s[start];
		else if (inquotes == '\'' && s[start] == '\'')
			inquotes = 0;
		else if (inquotes == '\"' && s[start] == '\"')
			inquotes = 0;
		tokenlen++;
		start++;
	}
	return (tokenlen);
}

static size_t	token_count(char *s)
{
	size_t			counter;
	unsigned int	i;
	int				into_token;
	char			inquotes;

	i = 0;
	counter = 0;
	into_token = 0;
	inquotes = 0;
	while (s[i])
	{
		counter += go_through_tokens(s[i], &into_token, &inquotes);
		i++;
	}
	if (into_token)
		counter += 1;
	return (counter);
}

static int	go_through_tokens(char c, int *into_token, char *inquotes)
{
	int	counter;

	counter = 0;
	if (ft_isspace(c))
	{
		if (*into_token && !(*inquotes))
		{
			*into_token = 0;
			counter = 1;
		}
	}
	else if (!(*into_token))
	{
		*into_token = 1;
		if (c == '\'' || c == '\"')
			*inquotes = c;
	}
	else if (!(*inquotes) && (c == '\'' || c == '\"'))
		*inquotes = c;
	else if (*inquotes == '\'' && c == '\'')
		*inquotes = 0;
	else if (*inquotes == '\"' && c == '\"')
		*inquotes = 0;
	return (counter);
}
