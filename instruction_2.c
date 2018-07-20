#include "corewar.h"

void	exec_and(t_process *process, unsigned int *arg, t_arg_type *arg_type)
{
	int		res;

	res = arg_fin(process, arg[0], arg_type[0]) & arg_fin(process, arg[1], arg_type[1]);
	process->reg[arg[2] - 1] = res;
	if (res == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void	exec_or(t_process *process, unsigned int *arg, t_arg_type *arg_type)
{
	int		res;

	res = arg_fin(process, arg[0], arg_type[0]) | arg_fin(process, arg[1], arg_type[1]);
	process->reg[arg[2] - 1] = res;
	if (res == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void	exec_xor(t_process *process, unsigned int *arg, t_arg_type *arg_type)
{
	int		res;

	res = arg_fin(process, arg[0], arg_type[0]) ^ arg_fin(process, arg[1], arg_type[1]);
	process->reg[arg[2] - 1] = res;
	if (res == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void	exec_zjmp(t_process *process, unsigned int *arg, t_arg_type *arg_type)
{
	if (process && arg && arg_type)
		return ;
}

void	exec_ldi(t_process *process, unsigned int *arg, t_arg_type *arg_type)
{
	if (process && arg && arg_type)
		return ;
}
