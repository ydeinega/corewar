#include "corewar.h"

funcptr	g_command[16] =
{
	exec_live,
	exec_ld,
	exec_st,
	exec_add,
	exec_sub,
	exec_and,
	exec_or,
	exec_xor,
	exec_zjmp,
	exec_ldi,
	exec_sti,
	exec_fork,
	exec_lld,
	exec_lldi,
	exec_lfork,
	exec_aff
};

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

void	exec_instruct(t_process *tmp)//это можно не выносить в отдельную ф-ию
{
	int move;

	move = g_command[tmp->opcode - 1](tmp);
	print_info_before_exec(tmp, move);//del
	
	tmp->opcode = 0;
	read_next_instruct(tmp, move);
	print_info_after_exec(tmp);//del
}

void	read_next_instruct(t_process *tmp, int move)
{
	int 			pc_prev;
	unsigned int	code;

	pc_prev = tmp->pc;
	tmp->pc = (tmp->pc + move) % MEM_SIZE;
	code = conv_hex(&g_game.board[tmp->pc], 1);
	if (code >= 1 && code <= 16)
	{
		tmp->opcode = code;
		tmp->cycles_to_exec = 10;//здесь нужно смотреть в табличке
	}
	//после того как мы все это сделали движение каретки записываем в верб, если этот
	//флаг имеется
	//if (g_game.v)
		// verb_add_pc_move(pc_prev, tmp->pc, move, g_game.board)
}

