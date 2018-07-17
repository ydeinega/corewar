#include "corewar.h"

void	run_processes(void)
{
	t_process	*tmp;

	tmp = g_game.proc;
	while (tmp)
	{
		if (tmp->live)
		{
			if (tmp->opcode >= 1 && tmp->opcode <= 16)
			{
				tmp->cycles_to_exec--;
				if (tmp->cycles_to_exec == 0)
					exec_instruct(tmp);
			}
			else
				read_next_instruct(tmp, 1);
		}
		tmp = tmp->next;
	}
}

void	exec_instruct(t_process *tmp)
{
	int move;

	move = 1;//это значение будет возвращать инструкция после исполнения
	tmp->opcode = 0;
	read_next_instruct(tmp, move);
}

void	read_next_instruct(t_process *tmp, int move)
{
	int pc_prev;

	pc_prev = tmp->pc;
	tmp->pc = (tmp->pc + move) % MEM_SIZE;
	if (g_game.board[tmp->pc] >= 1 && g_game.board[tmp->pc] <= 16)
	{
		tmp->opcode = g_game.board[tmp->pc];
		tmp->cycles_to_exec = 10;//здесь нужно смотреть в табличке
	}
	//после того как мы все это сделали движение каретки записываем в верб, если этот
	//флаг имеется
	//if (g_game.v)
		// verb_add_pc_move(pc_prev, tmp->pc, move, g_game.board)
}
