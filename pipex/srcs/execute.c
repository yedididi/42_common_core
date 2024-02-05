/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:15:27 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/21 13:55:36 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute(t_parse par, char **envp)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		error("pipe error");
	par.pid1 = fork();
	if (par.pid1 == -1)
		error("fork error");
	else if (par.pid1 == 0)
		child1(par, pipe_fd, envp);
	else
	{
		par.pid2 = fork();
		if (par.pid2 == -1)
			error("fork error");
		else if (par.pid2 == 0)
			child2(par, pipe_fd, envp);
		else
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			waitpid(par.pid1, NULL, 0);
			waitpid(par.pid2, NULL, 0);
		}
	}
}

void	child1(t_parse par, int *pipe_fd, char **envp)
{
	close(pipe_fd[0]);
	dup2(par.infile, 0);
	dup2(pipe_fd[1], 1);
	close(par.infile);
	close(pipe_fd[1]);
	execve(par.cmd1, par.cmd1_op, envp);
}

void	child2(t_parse par, int *pipe_fd, char **envp)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	dup2(par.outfile, 1);
	close(pipe_fd[0]);
	close(par.outfile);
	execve(par.cmd2, par.cmd2_op, envp);
}
