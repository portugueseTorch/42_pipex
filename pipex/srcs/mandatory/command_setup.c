/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:46:57 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/16 16:18:01 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	filter_cmd(a_t *a)
{
	close(a->pipe_fd[0]);
	if (a->i == 0)
	{
		dup2(a->in_file, STDIN_FILENO);
		dup2(a->pipe_fd[1], STDOUT_FILENO);
	}
	else if (a->i == (a->cmd_num - 1))
		dup2(a->out_file, STDOUT_FILENO);
	else
		dup2(a->pipe_fd[1], STDOUT_FILENO);
}

void	setup_cmd(a_t *a)
{
	a->cmds = ft_split(a->args[a->i], ' ');
	if (!a->cmds)
		err_handler(a, 2, "Error getting commands.\n");
	get_cmd_path(a);
	if (!a->cmd_path)
		err_handler(a, 2, "Error getting command path.\n");
}

void	get_cmd_path(a_t *a)
{
	char	*temp;
	int		ok;
	int		i;

	i = -1;
	ok = access(a->cmds[0], F_OK);
	if (ok == 0)
	{
		a->cmd_path = ft_strdup(a->cmds[0]);
		return ;
	}
	while (a->path[++i])
	{
		temp = ft_strjoin(a->path[i], a->cmds[0]);
		ok = access(temp, F_OK);
		if (ok < 0)
		{
			free(temp);
			continue ;
		}
		else
		{
			a->cmd_path = ft_strdup(temp);
			free(temp);
			return ;
		}
	}
	err_handler(a, 2, "Error getting command path\n");
}