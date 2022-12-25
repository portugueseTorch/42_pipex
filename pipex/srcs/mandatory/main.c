/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:31:53 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/25 12:56:14 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(t_a *a, char **envp)
{
	if (pipe(a->pipe_fd) == -1)
		err_handler(a, 2, "Error creating the pipe");
	a->pid = fork();
	if (a->pid == -1)
		err_handler(a, 2, "Error forking");
	if (a->pid == 0)
	{
		filter_cmd(a);
		setup_cmd(a);
		execve(a->cmd_path, a->cmds, envp);
	}
	close(a->pipe_fd[1]);
	wait(NULL);
	dup2(a->pipe_fd[0], STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	t_a	a;

	if (argc < 5)
	{
		ft_putstr_fd("Insufficient arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	setup(&a, argc, argv, envp);
	a.i = 0;
	while (a.i < a.cmd_num)
	{
		run_cmd(&a, envp);
		a.i++;
	}
	free_two(&a);
	return (0);
}
