#include "corewar.h"

void	run_game(void)
{
	// if (g_game.v)
	// 	initialize_verb();
	while (g_game.end != true || g_game.ctd > 0)
	{
		g_game.cycle++;
		// if (g_game.v)
		// 	start_verb(g_game.cycle, g_game.ctd);
		g_game.ctd_cur++;
		run_processes();
		if (g_game.ctd_cur == g_game.ctd)
			make_check();
		g_game.v && g_game.number_v ? verb_mode(g_game.number_v) : 0;
	}
	if ((!g_game.v && !g_game.dump && !g_game.visu) ||
		(g_game.v && !g_game.number_v))
		verb_mode(0);
}

void	make_check(void)
{
	bool	nbr_live;

	nbr_live = check_nbr_live();
	g_game.end = check_deaths();
	if (nbr_live)
	{
		g_game.ctd -= CYCLE_DELTA;
		g_game.checks = 0;
	}
	else
		g_game.checks++;
	if (g_game.checks == MAX_CHECKS)
	{
		g_game.ctd -= CYCLE_DELTA; 
		g_game.checks = 0;
	}
	if (g_game.end || g_game.ctd <= 0)
		g_game.end = true;
	g_game.ctd_cur = 0;
}

bool	check_nbr_live(void)
{
	int		i;
	bool	res;

	i = 0;
	res = 0;
	while (i < g_game.players)
	{
		if (g_game.player[i].lives_in_curr == NBR_LIVE)
			res = 1;
		g_game.player[i].lives_in_curr = 0;
		i++;
	}
	return (res);
}

bool	check_deaths(void)
{
	t_process	*proc;
	int			num_deaths;

	proc = g_game.proc;
	num_deaths = 0;
	while (proc)
	{
		if (!proc->lives_ctd)
		{
			proc->live = 0;
			num_deaths++;
			// if (g_game.v)
			// 	verb_add_death(proc->num, proc->cycles_not_live, g_game.ctd);
		}
		proc = proc->next;
	}
	return (num_deaths == g_game.proc_num ? 1 : 0);
}

// void	check_lives(int *zero_live, bool *nbr_live)
// {
// 	int		i;

// 	i = 0;
// 	while (i < g_game.players)
// 	{
// 		if (g_game.player[i].lives_in_curr == NBR_LIVE)
// 			*nbr_live = 1;
// 		if (g_game.player[i].lives_in_curr == 0)
// 			*zero_live += 1;
// 		g_game.player[i].lives_in_curr = 0;
// 		i++;
// 	}
// }
