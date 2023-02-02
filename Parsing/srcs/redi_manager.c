/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:15:31 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/13 10:05:28 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

/**
 |  open files asked by redirections, update fd input and output.
 |  redirections token and filename are erased after use, using ' '
 */
int	redi_manager(t_cmd *cmd, char *raw)
{
	int		i;
	char	inquotes;

	i = 0;
	inquotes = 0;
	while (raw[i])
	{
		if (redirection_hub(cmd, raw, i, inquotes) == 0)
			return (0);
		ocquotes(raw, &inquotes, i);
		i++;
	}
	return (1);
}
