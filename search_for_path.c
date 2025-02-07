/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:44 by jait-chd          #+#    #+#             */
/*   Updated: 2025/02/07 13:46:18 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*jo_in(char const *s1, char conect, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;

	if (!s1 || !s2 || !conect)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[y])
		str[x++] = s1[y++];
	str[x++] = conect;
	y = 0;
	while (s2[y])
		str[x++] = s2[y++];
	str[x] = '\0';
	return (str);
}

char	**cut_paths(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}
