/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:39:44 by yejlee2           #+#    #+#             */
/*   Updated: 2023/08/27 17:37:28 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell		minishell;
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	init(argc, envp, &minishell);
	start_shell(&minishell, envp);
	(void)argv;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	return (0);
}
