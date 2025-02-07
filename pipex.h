/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:54 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/07 13:59:28 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	execute(char *cmd, char *envp[]);
void	first_cmd_execute(int *fd, char **v, char **env);
void	second_cmd_execute(int *fd, char **v, char **env);
char	*jo_in(char const *s1, char conect, char const *s2);
char	**cut_paths(char *envp[]);

#endif
