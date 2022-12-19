/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:18:47 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/18 23:51:23 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_zero(a_t *a)
{
	if (a->in_file)
		close(a->in_file);
	if (a->out_file)
		close(a->out_file);
	if (a->heredoc)
		unlink(".store");
}

void	free_one(a_t *a)
{
	int	i;

	i = 0;
	free_zero(a);
	while (a->args[i])
		free(a->args[i++]);
	free(a->args);
}

void	free_two(a_t *a)
{
	int	i;

	i = 0;
	free_one(a);
	while (a->path[i])
		free(a->path[i++]);
	free(a->path);
}

void	err_handler(a_t *a, int err_code, char *err)
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