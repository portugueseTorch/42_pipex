/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:09:05 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/16 17:35:37 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"

typedef struct	a_s
{
	/* General info  */
	int		in_file;	// fd of the input file
	int		out_file;	// fd of the output file
	int		cmd_num;	// number of commands to be executed
	char	**args;		// array of all the commands
	char	**path;		// array of all paths from envp
	/* Specific info */
	int		pipe_fd[2];	// array to store the fds of the pipe
	int		i;			// iterator for the commands
	pid_t	pid;		// pid
	char	*cmd_path;	// string with the complete path for the command
	char	**cmds;		// array of the command split (like ["wc", "-l"])
	/* Heredoc info  */
	int		heredoc;	// flag to signal if it's heredoc
}				a_t;

//setup.c
void	setup(a_t *a, int argc, char **argv, char **envp);
void	pre_hd(a_t *a, int argc, char **argv);
void	heredoc(char **argv, int fd);
void	no_heredoc(a_t *a, int argc, char **argv);
char	**path_finder(a_t *a, char **envp);
//command_setup.c
void	setup_cmd(a_t *a);
void	get_cmd_path(a_t *a);
void	run_cmd(a_t *a, char **envp);
void	filter_cmd(a_t *a);
//free.c
void	err_handler(a_t *a, int err_code, char *err);
void	free_zero(a_t *a);
void	free_one(a_t *a);
void	free_two(a_t *a);
//utils.c
char	**get_args(a_t *a, char **argv);

#endif