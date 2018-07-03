
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:36:31 by ydeineha          #+#    #+#             */
/*   Updated: 2018/06/27 19:36:35 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	initialize_game(void)
{
	g_game.players = 0;
	g_game.champ = NULL;
	g_game.dump = false;
	g_game.visu = false;
	g_game.v = false;
	g_game.nbr_cycles = 0;
	g_game.nbr_cycles_visu = 0;
	g_game.number_v = 0;
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		usage();
	else
	{
		initialize_game();
		parse_args(argc, argv);
	}
}
