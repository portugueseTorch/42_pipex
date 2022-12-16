/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:09:48 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/16 17:10:21 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_args(a_t *a, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**args;
	
	args = (char **)malloc(sizeof(char *) * (a->cmd_num + 1));
	if (!args)
		err_handler(a, 0, "Error getting the commands.\n");
	i = 0;
	j = 2 + a->heredoc;
	while (i < a->cmd_num)
	{
		k = 0;
		while (argv[j][k] == ' ' || argv[j][k] == '\t')
			k++;
		if (argv[j][0] != '/')
			args[i] = ft_strjoin("/", &(argv[j][k]));
		else
			args[i] = ft_strdup(&(argv[j][k]));
		i++;
		j++;
	}
	args[i] = NULL;
	return(args);
}