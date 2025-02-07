/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:18 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/07 13:55:23 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char *envp[])
{
	int		i;
	char	**command;
	char	**paths;
	char	*way;

	i = 0;
	command = ft_split(cmd, ' ');
	paths = cut_paths(envp);
	while (paths[i])
	{
		way = jo_in(paths[i], '/', command[0]);
		if (access(way, F_OK | X_OK) == 0)
		{
			if (execve(way, command, NULL) == -1)
				perror("ERROR in execve func");
		}
		free(way);
		i++;
	}
	perror("ERROR");
}

void	first_cmd_execute(int *fd, char **v, char **env)
{
	int	infile;

	infile = open(v[1], O_RDONLY);
	if (infile < 0)
		perror("Eroor in infile");
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute(v[2], env);
}

void	second_cmd_execute(int *fd, char **v, char **env)
{
	int	outfile;

	outfile = open(v[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
		perror("error in outfile");
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execute(v[3], env);
	exit(EXIT_FAILURE);
}
