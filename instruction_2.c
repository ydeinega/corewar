#include "corewar.h"

unsigned int	arg_fin(t_process *process, unsigned int *arg, t_arg_type *arg_type, int i)
{
	int		res;

	res = 0;
	if (arg_type[i] == T_REG)
		res = process->reg[arg[i] - 1];
	else if (arg_type[i] == T_DIR)
		res = arg[i];
	else if (arg_type[i] == T_IND)
		res = extract_ind(process->pc, arg[i]);//base in func is IDX_MODE. Is it right?
	return (res);
}

void	exec_and(t_process *process, unsigned int *arg, t_arg_type *arg_type)
{
	int		res;

	res = arg_fin(process, arg, arg_type, 0) & arg_fin(process, arg, arg_type, 1);
	process->reg[arg[2] - 1] = res;
	if (res == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void	exec_or(t_process *process, unsigned int *arg)
{
	int		res;

	res = arg_fin(process, arg, arg_type, 0) | arg_fin(process, arg, arg_type, 1);
	process->reg[arg[2] - 1] = res;
	if (res == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void	exec_xor(t_process *process, unsigned int *arg)
{
	int		res;

	res = arg_fin(process, arg, arg_type, 0) ^ arg_fin(process, arg, arg_type, 1);
	process->reg[arg[2] - 1] = res;
	if (res == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void	exec_zjmp(t_process *process, unsigned int *arg)
{
	if (process && arg)
		return ;
}

void	exec_ldi(t_process *process, unsigned int *arg)
{
	if (process && arg)
		return ;
}
