/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:59:07 by yejlee2           #+#    #+#             */
/*   Updated: 2023/02/11 14:19:51 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_parse	par;

	if (argc != 5)
		error("doesnt have 4 arguments");
	par.infile = open(argv[1], O_RDONLY);
	if (par.infile == -1)
		error("infile open error");
	par.outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (par.outfile == -1)
		error("outfile open error");
	parse(argv, &par, envp);
	execute(par, envp);
	free_member(&par);
}

void	error(char *message)
{
	perror(message);
	exit(1);
}

void	free_double(char **str, int i)
{
	while (str[i])
	{
		ft_memset(str[i], 0, ft_strlen(str[i]));
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

void	free_member(t_parse *par)
{
	free(par->cmd1);
	free(par->cmd2);
	free_double(par->cmd1_op, 1);
	free_double(par->cmd2_op, 1);
}
