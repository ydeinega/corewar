/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verb_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 21:25:43 by dgonor            #+#    #+#             */
/*   Updated: 2018/07/20 21:25:45 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbosity.h"

void		verb_print_lives()
{
//	ft_printf("6 SEGFOLT?\n");
	int 		i;
	int 		num_players;
	t_player	*player;

	player = NULL;
	i = -1;
	num_players = g_game.players;
	player = g_game.player;
	if (g_game.player)
	{
		g_game.
		player = g_game.player;
		while (++i < num_players)
			ft_printf("Player %i (%s) is said to be alive\n", i + 1, player->name);
	}
}

void		verb_print_cycles()
{
//	ft_printf("5 SEGFOLT?\n");
	int 	cycle;
	cycle = g_verb.cycle;
	if (g_verb.cycle)
		ft_printf("It is now cycle %i\n", cycle);
//	if ((g_verb.ctd_change))
//		ft_printf("Cycle to die is now %i\n", g_verb.);
}

void		verb_print_op()
{
//	ft_printf("4 SEGFOLT?\n");
	ft_printf("OP");
	t_list_op	*op;
	int 		i;

	i = -1;
	op = g_verb.op;
	ft_printf("P\t%i |", op->arg_num);
//	if (op->arg)
//		op->arg_num;
}

void		verb_print_death()
{
//	ft_printf("3 SEGFOLT?\n");
	t_list_death	*death;

	death = NULL;
	if (g_verb.death)
	{
		death = g_verb.death;
		while (death)
		{
			ft_printf("Process %i ", death->proc_num);
			ft_printf("hasn't lived for %i cycles ", death->cycles_not_live);
			ft_printf("(CTD %i)\n", g_game.ctd);
			death = death->next;
		}
	}
	//	ft_printf("Process %i hasn't lived for %i cycles (CTD %i)\n", op->proc_num, death->cycles_not_live, g_verb.ctd);
}

void		verb_print_pc()
{
//	ft_printf("2 SEGFOLT?\n");
	t_list_pc	*pc;
	int 		i;

	i = -1;
	pc = g_verb.pc;
	if (g_verb.pc)
	{
		ft_printf("ADV %i ", pc->move);
		pc->pc_prev == 0 ? ft_printf("(0x0000 -> "): ft_printf("(%#.4x -> ", pc->pc_prev);
		pc->pc_new == 0 ? ft_printf("0x0000)") : ft_printf("%#.4x)", pc->pc_new);
		while (++i < pc->move)
			ft_printf(" %.2x", pc->line[i]);
		ft_printf("\n");
	}
//	ft_printf("%s %i (%#.4x -> %#.4x) %s\n","ADV", pc->move, pc->pc_prev, pc->pc_new, pc->line);
}
