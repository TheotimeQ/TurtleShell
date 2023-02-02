/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:08 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/14 13:01:24 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static int	check_pipe_syntax(char *prompt);
static int	isstartpipe(char *prompt);
static int	init_toexec(t_sh *sh, char *prompt);
static void	check_consecpipe(char *prompt, int i, int *isok);

/**
 |  Deals the main parsing steps after previous syntax error checking.
 |  Open heredocs prompts if needed.
 |  And then send the result to execution.
 */
int	proc_parsing(t_sh *sh, char *prompt)
{
	sh->to_exec = malloc(sizeof(t_to_exec));
	if (!sh->to_exec)
		return (0);
	sh->to_exec->nb_cmd = -1;
	sh->to_exec->all_cmd = NULL;
	if (!init_toexec(sh, prompt))
		return (0);
	g_cmd_running = 1;
	here_docs(sh);
	if (g_cmd_running != 200)
		exec(sh);
	free_to_exec(sh);
	return (1);
}

/**
 |  Go through spliting func to divide the pipeline
 |  Then extract the content of each interpipe as a char **av
 */
static int	init_toexec(t_sh *sh, char *prompt)
{
	char	**raw_inpipe;

	if (!check_pipe_syntax(prompt) || isstartpipe(prompt))
		return (err_man(PIPESYN), 0);
	sh->to_exec->nb_cmd = count_cmds(prompt);
	raw_inpipe = splitpipe(prompt, sh->to_exec->nb_cmd);
	if (!raw_inpipe)
		return (err_man(MALLOC), 0);
	if (!ext_inpipe(sh, raw_inpipe))
		return (ft_strsdel(&raw_inpipe), 0);
	ft_strsdel(&raw_inpipe);
	return (1);
}

static int	isstartpipe(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '|')
			return (1);
		else if (!ft_isspace(prompt[i]))
			return (0);
		i++;
	}
	return (0);
}

// We want something else than whitespaces beetween two pipes
static int	check_pipe_syntax(char *prompt)
{
	int		i;
	int		isok;
	char	inquotes;

	i = 0;
	isok = 1;
	inquotes = 0;
	while (prompt[i])
	{
		if (!inquotes && prompt[i] == '|')
			check_consecpipe(prompt, i, &isok);
		ocquotes(prompt, &inquotes, i);
		i++;
	}
	return (isok);
}

// set isok boolean to 0 is there is two consecutives pipes
static void	check_consecpipe(char *prompt, int i, int *isok)
{
	int	j;

	j = 1;
	while (prompt[i + j])
	{
		if (prompt[i + j] == '|')
			*isok = 0;
		else if (!ft_isspace(prompt[i + j]))
			break ;
		j++;
	}
}
