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

void	exec_instruct(t_process *proc)//это можно не выносить в отдельную ф-ию
{
	t_arg_type	*arg_type;
	int			arg_num;
	int			move;
	int			*arg;
	t_op		op;

	arg_type = NULL;
	arg = NULL;
	op = op_tab[proc->opcode - 1];
	arg_num = op.arg_num;
	if (op.codage)
		arg_type = get_codage(proc, arg_num);
	if (!op.codage || (op.codage && codage_valid(arg_type, op.arg, arg_num)))
	{
		arg = extract_arg(op, proc->pc, arg_type);
		g_command[proc->opcode - 1](proc, arg);
		if (proc->opcode == 1)
			proc->lives_ctd++;
		else
			proc->cycles_not_live++;
		//print_arg(arg, proc->opcode);//del
		// if (g_game.v)
		// 	verb_add_to_op(proc->opcode, arg_type, arg);
		
	}
	move = get_move(proc, argument);
	// print_info_before_exec(proc, move);//del
	proc->opcode = 0;
	read_next_instruct(proc, move);
	// print_info_after_exec(proc);//del
	//free(arg_type);
	//free(arg);
}

void	read_next_instruct(t_process *proc, int move)
{
	int 			pc_prev;
	unsigned int	code;

	pc_prev = proc->pc;
	proc->pc = (proc->pc + move) % MEM_SIZE;
	code = conv_hex(&g_game.board[proc->pc], 1);
	if (code >= 1 && code <= 16)
	{
		proc->opcode = code;
		proc->cycles_to_exec = op_tab[code - 1].cycles_to_exec;//здесь нужно смотреть в табличке
	}
	//после того как мы все это сделали движение каретки записываем в верб, если этот
	//флаг имеется
	//if (g_game.v)
		// verb_move_pc_move(pc_prev, proc->pc, move, g_game.board)
}

