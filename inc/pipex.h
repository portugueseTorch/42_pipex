/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:09:05 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/19 15:40:15 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wait.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"

typedef struct s_a
{
	int		in_file;
	int		out_file;
	int		cmd_num;
	char	**args;
	char	**path;
	int		pipe_fd[2];
	int		i;
	pid_t	pid;
	char	*cmd_path;
	char	**cmds;
	int		heredoc;
}				t_a;

//setup.c
void	setup(t_a *a, int argc, char **argv, char **envp);
void	pre_hd(t_a *a, int argc, char **argv);
void	heredoc(char **argv, int fd);
void	no_heredoc(t_a *a, int argc, char **argv);
char	**path_finder(t_a *a, char **envp);
//command_setup.c
void	setup_cmd(t_a *a);
void	get_cmd_path(t_a *a);
void	run_cmd(t_a *a, char **envp);
void	filter_cmd(t_a *a);
//free.c
void	err_handler(t_a *a, int err_code, char *err);
void	free_zero(t_a *a);
void	free_one(t_a *a);
void	free_two(t_a *a);
//utils.c
char	**get_args(t_a *a, char **argv);

#endif