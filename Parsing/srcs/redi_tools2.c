/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumarti <loumarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:49:48 by loumarti          #+#    #+#             */
/*   Updated: 2023/01/19 10:56:58 by loumarti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/turtle_parsing.h"

static int	redi_to(t_cmd *cmd, char *raw, int *start, int append);
static int	redi_to2(t_cmd *cmd, char *filename, int append);
static int	redi_from(t_cmd *cmd, char *raw, int *start);
static int	redi_from2(t_cmd *cmd, char *filename);

int	redirection_hub(t_cmd *cmd, char *raw, int i, char inquotes)
{
	if (!inquotes && raw[i] == '>' && raw[i + 1] == '>')
	{
		if (!redi_to(cmd, raw, &i, 1))
			return (0);
	}
	else if (!inquotes && raw[i] == '<' && raw[i + 1] != '<')
	{
		if (!redi_from(cmd, raw, &i))
			return (0);
	}
	else if (!inquotes && raw[i] == '<' && raw[i + 1] == '<')
	{
		if (!pre_heredoc(cmd, raw, i))
			return (0);
	}
	else if (!inquotes && raw[i] == '>' && raw[i + 1] != '>')
	{
		if (!redi_to(cmd, raw, &i, 0))
			return (0);
	}
	return (1);
}

// [>] and [>>] management
static int	redi_to(t_cmd *cmd, char *raw, int *start, int append)
{
	char	*filename;
	int		len;

	*start += 1 + append;
	raw[(*start) - 1] = ' ';
	raw[(*start) - 1 - append] = ' ';
	filename = ext_filename(raw, start, &len);
	if (!filename)
		return (0);
	if (!redi_to2(cmd, filename, append))
		return (free(filename), 0);
	*start += len - 1;
	return (free(filename), 1);
}

/**
 |  @brief open, and create if doesn't exist a file which is
 |  represented by filname. Append if it was a [>>] token.
 |  incorporated in t_cmd *cmd. If there were a previous fd open,
 |  it try closing it before.
 */
static int	redi_to2(t_cmd *cmd, char *filename, int append)
{
	int	fd;

	if (append)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (file_err(filename), 0);
	if (cmd->output_fd != 1)
	{
		if (close(cmd->output_fd) == -1)
			perror("🐢");
	}
	cmd->output_fd = fd;
	return (1);
}

// [<] management
static int	redi_from(t_cmd *cmd, char *raw, int *start)
{
	char	*filename;
	int		len;

	*start += 1;
	raw[(*start) - 1] = ' ';
	filename = ext_filename(raw, start, &len);
	if (!filename)
		return (0);
	if (!redi_from2(cmd, filename))
		return (free(filename), 0);
	return (free(filename), 1);
}

static int	redi_from2(t_cmd *cmd, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (file_err(filename), 0);
	if (cmd->input_fd != 0)
	{
		if (close(cmd->input_fd) == -1)
			perror("🐢");
	}
	cmd->input_fd = fd;
	cmd->hdocwon = 0;
	return (1);
}
