#include "corewar.h"

void	exec_live(t_process *process, int *arg)
{
	int				champ_num;

	champ_num = -(*arg);
	if (champ_num > 0 && champ_num < g_game.players)
	{
		g_game.player_last_live = champ_num;
		g_game.player[champ_num - 1].lives_in_curr++;
		g_game.player[champ_num - 1].last_live = g_game.cycle;
	}
	//Subject! Check!
}

void	exec_ld(t_process *process, int *arg)
{
	if (process && arg)
		return ;
}

void	exec_st(t_process *process, int *arg)
{
	if (process && arg)
		return ;
}

void	exec_add(t_process *process, int *arg)
{
	if (process && arg)
		return ;
}

void	exec_sub(t_process *process, int *arg)
{
	if (process && arg)
		return ;
}
