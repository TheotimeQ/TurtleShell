/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:31:43 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/14 13:40:41 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static int	dollar_pattern_len(char *raw_inpipe, int dollpos, int *is_exit);
static void	swap_dollar2(t_sh *sh, char **raw_inpipe, int dollpos, char *value);
static char	*deal_value(t_sh *sh, char *pattern, int is_exit);

void	swap_dollar(t_sh *sh, char **raw_inpipe, int dollpos)
{
	int		patternlen;
	char	*pattern;
	char	*value;
	int		is_exit;

	patternlen = dollar_pattern_len(*raw_inpipe, dollpos, &is_exit);
	pattern = ft_substr(*raw_inpipe, dollpos + 1, patternlen - 1);
	if (!pattern)
		free_exit_sh(sh, 1);
	value = deal_value(sh, pattern, is_exit);
	swap_dollar2(sh, raw_inpipe, dollpos, value);
	free(pattern);
	if (is_exit)
		free(value);
}

static char	*deal_value(t_sh *sh, char *pattern, int is_exit)
{
	t_var	*var;
	char	*value;

	if (is_exit)
	{
		value = ft_itoa(sh->last_ret);
		if (!value)
			free_exit_sh(sh, 1);
	}
	else
	{
		var = env_get(sh->env_var, pattern);
		if (var == NULL)
			value = "";
		else
			value = var->value;
	}
	return (value);
}

static int	dollar_pattern_len(char *raw_inpipe, int dollpos, int *is_exit)
{
	int	i;

	*is_exit = 0;
	if (ft_isdigit(raw_inpipe[dollpos + 1]))
		return (2);
	if (raw_inpipe[dollpos + 1] == '?')
	{
		*is_exit = 1;
		return (2);
	}
	i = 1;
	while (ft_isalpha(raw_inpipe[i + dollpos])
		|| ft_isdigit(raw_inpipe[i + dollpos]))
		i++;
	return (i);
}

static void	swap_dollar2(t_sh *sh, char **raw_inpipe, int dollpos, char *value)
{
	char	*newtoken;
	int		patternlen;
	int		is_exit;

	patternlen = dollar_pattern_len(*raw_inpipe, dollpos, &is_exit);
	newtoken = ft_strnew(ft_strlen(*raw_inpipe) + ft_strlen(value));
	if (!newtoken)
		free_exit_sh(sh, 1);
	ft_strncpy(newtoken, *raw_inpipe, dollpos);
	ft_strcat(newtoken, value);
	ft_strcat(newtoken, *raw_inpipe + dollpos + patternlen);
	ft_strdel(raw_inpipe);
	*raw_inpipe = newtoken;
}
