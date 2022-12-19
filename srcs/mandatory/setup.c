/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:08:48 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/19 15:44:27 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup(t_a *a, int argc, char **argv, char **envp)
{
	if (!ft_strncmp(argv[1], "here_doc", 9))
		pre_hd(a, argc, argv);
	else
		no_heredoc(a, argc, argv);
	a->cmd_num = argc - 3 - a->heredoc;
	a->args = get_args(a, argv);
	a->path = path_finder(a, envp);
}

void	pre_hd(t_a *a, int argc, char **argv)
{
	int	temp;

	if (argc < 6)
	{
		ft_putstr_fd("Heredoc needs at least 6 args to run\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	a->heredoc = 1;
	a->out_file = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	temp = open(".store", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (a->out_file == -1 || temp == -1)
		err_handler(a, 0, "Error while setting up.\n");
	heredoc(argv, temp);
	close(temp);
	a->in_file = open(".store", O_RDONLY);
	if (a->in_file == -1)
		err_handler(a, 0, "Error while setting up.\n");
}

void	heredoc(char **argv, int fd)
{
	char	*temp;
	char	*lim;
	char	*line;

	temp = ft_strdup(argv[2]);
	lim = ft_strjoin(temp, "\n");
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (ft_strlen(line) == ft_strlen(lim))
			if (!ft_strncmp(lim, line, ft_strlen(lim)))
				break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(temp);
	free(lim);
	free(line);
}

void	no_heredoc(t_a *a, int argc, char **argv)
{
	a->heredoc = 0;
	a->in_file = open(argv[1], O_RDONLY);
	a->out_file = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (a->in_file == -1 || a->out_file == -1)
		err_handler(a, 0, "Error while setting up.\n");
}

char	**path_finder(t_a *a, char **envp)
{
	int		i;
	char	*line;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			line = ft_strdup(&(envp[i][5]));
			break ;
		}
		i++;
	}
	if (!line)
		err_handler(a, 1, "Error while setting up.\n");
	path = ft_split(line, ':');
	free(line);
	return (path);
}
