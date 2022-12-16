/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:31:53 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/16 17:05:59 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(a_t *a, char **envp)
{
	if (pipe(a->pipe_fd) == -1)
		err_handler(a, 2, "Error creating the pipe.\n");
	a->pid = fork();
	if (a->pid == -1)
		err_handler(a, 2, "Error forking.\n");
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
	a_t	a;

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

// ./build/bin/pipex input.txt "grep give" "grep up" "wc -l" out.txt
//	   0		1			2			 3	    4		argc=5, cmd=2
// ./build/bin/pipex here_doc EOF "grep biciqueleta" "wc -l" out.txt
//	   0	   1	 2			 3			  4		   5	argc=6, cmd=2
