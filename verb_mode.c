#include "corewar.h"

void	verb_mode(int number_v)
{
	int	win;

	win = g_game.player_last_live;
	if (g_game.cycle == 1 || !number_v)
		introduce_contestants();
	if (g_game.end)
		ft_printf("Contestant %d, \"%s\", has won !\n", win, g_game.player[win].name);
}

void	introduce_contestants()
{
	ft_printf("Introducing contestants...\n");
}

// void	verb_add_pc_move(int pc_prev, int pc_new, int move, unsigned char *board)
// {
//		ADV 6 (0x059f -> 0x05a5) 0a 94 ff f4 0a 0b
// }

// void	verb_add_death(int proc_num, int cycles_not_live, int ctd)
// {
//		Инфа выводится в след порядке
//		Process 29 hasn't lived for 1460 cycles (CTD 986)
//		Process 9 hasn't lived for 1026 cycles (CTD 986)
//		Process 6 hasn't lived for 1909 cycles (CTD 986)
// }
