#include "corewar.h"

void	exec_and(t_process *process, unsigned int *arg)
{
	t_op	op;
	// int		i;
	// int		arg_fin;

	op = op_tab[process->opcode - 1];
	if (process && arg)
		return ;

}

void	exec_or(t_process *process, unsigned int *arg)
{
	if (process && arg)
		return ;
}

void	exec_xor(t_process *process, unsigned int *arg)
{
	if (process && arg)
		return ;
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
