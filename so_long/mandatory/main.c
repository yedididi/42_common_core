/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:03:34 by yejlee2           #+#    #+#             */
/*   Updated: 2023/03/30 11:27:17 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/so_long.h"

void	test(t_map sinnoh)
{
	int	i;

	i = 0;
	while (sinnoh.map[i])
	{
		printf("%s\n", sinnoh.map[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_game	mix;

	if (argc != 2)
		error("argument error");
	init(&mix);
	check_map(argv[1], &(mix.sinnoh), &(mix.param));
	test(mix.sinnoh);
	printf("\n\n");
	if (escapable(&mix) == 0)
		error("not escapable");
	test(mix.sinnoh);
	play_game(&mix);
}

void	error(char *message)
{
	write(1, "Error\n", 6);
	perror(message);
	exit(1);
}
