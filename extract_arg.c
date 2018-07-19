#include "corewar.h"

int				*extract_arg(t_op op, int pc, t_arg_type *arg_type)
{
	int				i;
	int				length;
	int				*arg;
	unsigned char	*line;

	i = 0;
	length = 0;
	pc = op.codage ? pc + 1 : pc;
	arg = (int *)malloc(sizeof(int) * op.arg_num);//if !line malloc failed
	line = NULL;
	while (i < op.arg_num)
	{
		if (arg_type)
		{
			if (arg_type[i] == T_REG)
				length = 1;
			else if (arg_type[i] == T_DIR)
				length = op.label;
			else if (arg_type[i] == T_IND)
				length = IND_SIZE;
		}
		else
			length = op.label;
		line = extract_line(&pc, length);
		arg[i] = conv_hex(line, length);
		free(line);
		i++;
	}
	return (arg);
}

unsigned char	*extract_line(int *pc, int length)
{
	int 			new_pc;
	int 			i;
	unsigned char	*line;

	i = 0;
	new_pc = *pc;
	line = (unsigned char *)malloc(sizeof(unsigned char) * length);
	while (i < length)
	{
		new_pc = (new_pc + 1) % MEM_SIZE;
		line[i] = g_game.board[new_pc];
		i++;
	}
	*pc = new_pc;
	return (line);
}
