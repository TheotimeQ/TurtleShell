/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi_dealer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:17:26 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/19 09:45:58 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static int	isdollar(char *token, int *dollpos);
static int	isdollar_doc(char *raw_inpipe, int *dollpos);

/**
 |  Environnment variable rules
 |
 |  "$A"			-> translate
 |  '$A'			-> nop
 |  "  '$A'  "		-> translate
 |  '  "$A"  '		-> nop
 |  $?				-> translate (get last exit code)
 |  $[0-9]			-> translate (replace by "")
 |  $[alpha][alphanum] -> translate (all)
 |  $[ws + '\0']	-> nop
 */

/**
 |  @brief go through each token and replace $[NAME](ws)
 |  patterns which arn't in single quote
 |
 |  @param sh needed to get environment values
 |  @param token -> a token address (address of a char *)
 */
void	swap_env(t_sh *sh, char **raw_inpipe)
{
	int	dollpos;
	int	goon;

	goon = 1;
	while (goon)
	{
		if (isdollar(*raw_inpipe, &dollpos))
		{
			swap_dollar(sh, raw_inpipe, dollpos);
			goon = 1;
		}
		else
		{
			goon = 0;
		}
	}
}

void	swap_env_doc(t_sh *sh, char **raw_inpipe)
{
	int	dollpos;
	int	goon;

	goon = 1;
	while (goon)
	{
		if (isdollar_doc(*raw_inpipe, &dollpos))
		{
			swap_dollar(sh, raw_inpipe, dollpos);
			goon = 1;
		}
		else
		{
			goon = 0;
		}
	}
}

// return the index of the first $VAR pattern to translate, else 0
static int	isdollar(char *raw_inpipe, int *dollpos)
{
	char	inquotes;
	int		i;

	i = 0;
	inquotes = 0;
	while (raw_inpipe[i])
	{
		if ((!inquotes || inquotes == '\"') && raw_inpipe[i] == '$')
		{
			if (!ft_isspace(raw_inpipe[i + 1]) && raw_inpipe[i + 1] != '\0')
			{
				if (!(inquotes == '\"' && raw_inpipe[i + 1] == '\"'))
				{
					*dollpos = i;
					return (1);
				}
			}
		}
		ocquotes(raw_inpipe, &inquotes, i);
		i++;
	}
	return (0);
}

static int	isdollar_doc(char *raw_inpipe, int *dollpos)
{
	int		i;

	i = 0;
	while (raw_inpipe[i])
	{
		if (raw_inpipe[i] == '$')
		{
			if (!ft_isspace(raw_inpipe[i + 1]) && raw_inpipe[i + 1] != '\0')
			{
				*dollpos = i;
				return (1);
			}
		}
		i++;
	}
	return (0);
}
