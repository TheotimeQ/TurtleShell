/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:12 by tquere            #+#    #+#             */
/*   Updated: 2023/01/07 15:35:19 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	free_split(char **tab, int tab_size)
{
	int	index;

	index = 0;
	while (index < tab_size)
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}

static int	fill_tab(char const *s, char c, char **tab)
{
	int		index_tab;
	int		index_s;
	int		start;

	index_s = 0;
	index_tab = 0;
	while (s[index_s])
	{
		while (s[index_s] && s[index_s] == c)
			index_s++;
		start = index_s;
		while (s[index_s] && s[index_s] != c)
			index_s++;
		if (start < index_s)
		{
			tab[index_tab] = ft_substr(s, start, index_s - start);
			if (tab[index_tab++] == NULL)
			{
				free_split(tab, index_tab);
				return (-1);
			}
		}
	}
	return (index_tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		index_tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (tab == NULL)
		return (NULL);
	index_tab = fill_tab(s, c, tab);
	free_split(tab, index_tab);
	tab = malloc(sizeof(char *) * (index_tab + 1));
	if (tab == NULL)
		return (NULL);
	index_tab = fill_tab(s, c, tab);
	if (index_tab >= 0)
		tab[index_tab] = NULL;
	return (tab);
}
