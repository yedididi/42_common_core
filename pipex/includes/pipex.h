/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:04:52 by yejlee2           #+#    #+#             */
/*   Updated: 2023/02/11 14:09:13 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_parse
{
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;
	char	**cmd1_op;
	char	**cmd2_op;
	pid_t	pid1;
	pid_t	pid2;
}	t_parse;

void	error(char *message);
void	parse(char *argv[], t_parse *par, char **envp);
char	*get_cmd_path(char **path, char *cmd);
char	**pretty_cmd(char *cmd);
char	*remove_quote(char *str);
void	free_double(char **str, int i);
void	free_member(t_parse *par);
void	execute(t_parse par, char **envp);
void	child1(t_parse par, int *pipe_fd, char **envp);
void	child2(t_parse par, int *pipe_fd, char **envp);

#endif