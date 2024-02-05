/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:11:07 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/15 13:22:57 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int	EXIT_STATUS;

void	fill_heredoc(int random_fd);

int main(void)
{
    char			random_name[8];
	int				random_fd;
	DIR				*tmp_dir;
	struct dirent	*tmp_info;
    char            *filename;
    char            *dir_file;
    int             i;

    i = 0;
	random_fd = open("/dev/urandom", O_RDONLY);
	if (read(random_fd, random_name, 8) == -1)
		exit(1);
	close(random_fd);
    while (8 > i)
	{
		if (random_name[i] < 0)
			random_name[i] = random_name[i] * -1;
		random_name[i] = random_name[i] % 26 + 'a';
		i++;
	}
	filename = strdup(random_name);
	tmp_dir = opendir("/tmp");
	tmp_info = readdir(tmp_dir);
	while (tmp_info)
	{
		if (strncmp(random_name, tmp_info->d_name, 8) == 0)
		{
			closedir(tmp_dir);
			return (0);
		}
		tmp_info = readdir(tmp_dir);
	}
	dir_file = ft_strjoin("/tmp/", random_name);
	random_fd = open(dir_file, O_RDWR | O_CREAT | O_APPEND, 0644); //random file open
	free(dir_file);
	fill_heredoc(random_fd);
}

void	fill_heredoc(int random_fd)
{
	int		status;
	pid_t	pid;
	char *str;

	pid = fork();
	if (pid == 0)
	{
		str = get_next_line(0);
		while (str)
		{
			write(random_fd, str, ft_strlen(str));
			str = get_next_line(0);
		}
		close(random_fd);
		exit(0);
	}
	else if (pid == -1)
		exit(1);
	waitpid(pid, &status, 0);
	EXIT_STATUS = WEXITSTATUS(status);
	printf("exit status : %d\n", EXIT_STATUS);
}

