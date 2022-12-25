/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:18:47 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/25 13:28:28 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_zero(t_a *a)
{
	if (a->in_file)
		close(a->in_file);
	if (a->out_file)
		close(a->out_file);
	if (a->heredoc)
		unlink(".store");
}

void	free_one(t_a *a)
{
	int	i;

	i = 0;
	free_zero(a);
	while (a->args[i])
		free(a->args[i++]);
	free(a->args);
}

void	free_two(t_a *a)
{
	int	i;

	i = 0;
	free_one(a);
	while (a->path[i])
		free(a->path[i++]);
	free(a->path);
	if (a->pid == 0)
	{
		if (a->cmds)
		{
			i = 0;
			while (a->cmds[i])
				free(a->cmds[i++]);
			free(a->cmds);
		}
	}
}

void	err_handler(t_a *a, int err_code, char *err)
{
	if (err_code == 0)
		free_zero(a);
	else if (err_code == 1)
		free_one(a);
	else if (err_code == 2)
		free_two(a);
	perror(err);
	exit(EXIT_FAILURE);
}
