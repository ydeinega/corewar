#include "corewar.h"

t_arg_type	*get_codage(t_process *process)
{
	t_arg_type		arg[3];
	int				codage_pc;
	unsigned int	codage;

	codage_pc = (process->pc + 1) % MEM_SIZE;
	codage = conv_hex(&g_game.board[codage_pc], 1);
	
}