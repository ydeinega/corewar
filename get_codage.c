#include "corewar.h"

t_arg_type	*get_codage(t_process *process, int arg_num)
{
	t_arg_type		*arg;
	int				codage_pc;
	unsigned int	codage;
	int				i;
	int				shift;

	i = 0;
	shift = 6;
	codage_pc = (process->pc + 1) % MEM_SIZE;
	codage = conv_hex(&g_game.board[codage_pc], 1);
	arg = ft_strnew(arg_num);
	while (i < arg_num)
	{
		arg[i] = (codage >> shift) & 3;
		shift -= 2;
		i++;
	}
	print_codage(codage, arg, arg_num);//
	return (arg);
}

