/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:58:58 by yejlee2           #+#    #+#             */
/*   Updated: 2023/02/11 14:19:13 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parse(char *argv[], t_parse *par, char **envp)
{
	char	*path;
	char	**sp_path;

	par->cmd1_op = pretty_cmd(argv[2]);
	par->cmd2_op = pretty_cmd(argv[3]);
	ft_memset(&path, 0, 1);
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
		{
			path = *envp + 5;
			break ;
		}
		envp++;
	}
	sp_path = ft_split(path, ':');
	par->cmd1 = get_cmd_path(sp_path, par->cmd1_op[0]);
	par->cmd2 = get_cmd_path(sp_path, par->cmd2_op[0]);
	if (par->cmd1 == 0 || par->cmd2 == 0)
		perror("command not found");
	free_double(sp_path, 0);
}

char	**pretty_cmd(char *cmd)
{
	char	**return_str;

	return_str = 0;
	if (ft_strncmp("awk", cmd, 3) == 0)
	{
		return_str = (char **)malloc(sizeof(char *) * 3);
		return_str[0] = ft_strdup("awk");
		return_str[1] = remove_quote(cmd + 4);
		return_str[2] = 0;
	}
	else
		return_str = ft_split(cmd, ' ');
	return (return_str);
}

char	*remove_quote(char *str)
{
	char	*return_str;

	return_str = str;
	if ((str[0] == 39) && (str[ft_strlen(str) - 1] == 39))
	{
		str[ft_strlen(str) - 1] = 0;
		return_str = ft_strdup(str + 1);
	}
	return (return_str);
}

char	*get_cmd_path(char **path, char *cmd)
{
	int		i;
	char	*str;
	int		fd;
	char	*temp;

	i = 0;
	temp = ft_strjoin("/", cmd);
	free(cmd);
	cmd = temp;
	while (path[i])
	{
		str = ft_strjoin(path[i], cmd);
		fd = access(str, X_OK);
		if (fd != -1)
		{
			free(cmd);
			return (str);
		}
		free(str);
		i++;
	}
	free(cmd);
	return (0);
}
