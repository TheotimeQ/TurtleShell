/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:51:59 by tquere            #+#    #+#             */
/*   Updated: 2023/01/14 09:48:59 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/exec.h"

static int	check_args(char *args)
{
	int		i;

	i = 1;
	while (args[i])
	{	
		if (args[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	echo_print(t_cmd *cmd, char **args, int i, int flag)
{
	while (args[i])
	{
		ft_putstr_fd(args[i], cmd->output_fd);
		if (args[i + 1] && args[i][0] != '\0')
			write(cmd->output_fd, " ", 1);
		i++;
	}
	if (!flag)
		write(cmd->output_fd, "\n", 1);
}

void	exec_echo(t_cmd *cmd, char **args)
{	
	int		i;
	int		flag;

	flag = 0;
	cmd->ret = 0;
	i = 1;
	if (ft_count_tab(args) == 1)
	{
		write(cmd->output_fd, "\n", 1);
		return ;
	}
	while (args[i] && ft_strncmp(args[i], "-n", 2) == 0 && check_args(args[i]))
	{
		flag = 1;
		i++;
	}
	if (flag && ft_count_tab(args) > 1)
		echo_print(cmd, args, i, flag);
	if (!flag)
		echo_print(cmd, args, i, flag);
}
