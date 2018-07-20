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

static t_arg_type	*get_arg_type(t_process *proc)
{
	t_arg_type		*arg_type;

	arg_type = NULL;
	if (op.codage)
		arg_type = get_codage(proc, op.arg_num);
	else
	{
		arg_type = ft_strnew(op.arg_num);
		ft_memcpy(arg_type, op.arg, op.arg_num);
	}
	return (arg_type);
}

void	exec_instruct(t_process *proc)
{
	t_arg_type		*arg_type;
	int				move;
	unsigned int	*arg;
	t_op			op;

	op = op_tab[proc->opcode - 1];
	arg_type = get_arg_type(proc);
	arg = NULL;
	if (!op.codage || (op.codage && codage_valid(arg_type, op.arg, op.arg_num)))
	{
		arg = extract_arg(op, proc->pc, arg_type);
		g_command[proc->opcode - 1](proc, arg);
		if (proc->opcode == 1)
			proc->lives_ctd++;
		else
			proc->cycles_not_live++;
		print_arg(arg, proc->opcode);//del
		//ЗАПИСЬ В ВЕРБ
		// if (g_game.v)
		// 	verb_add_to_op(proc, arg_type, arg);
		
	}
	//there can be functions that change pc and I should not call move then
	//zjmp, for instance
	//other???
	move = get_move(proc, arg_type);//here in move I should try to handle it
	//print_info_before_exec(proc, move);//del
	proc->opcode = 0;
	read_next_instruct(proc, move);
	//print_info_after_exec(proc);//del
	arg_type ? free(arg_type) : 0;
	arg ? free(arg) : 0;
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
	//ЗАПИСЬ В ВЕРБ
	//if (g_game.v)
		// verb_move_pc_move(pc_prev, proc->pc, move, g_game.board)
}

