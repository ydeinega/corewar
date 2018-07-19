#include "corewar.h"

static int		get_length(t_arg_type arg_type)
{
	int	length;

	length = 0;
	if (arg_type[i] == T_REG)
		length = 1;
	else if (arg_type[i] == T_DIR)
		length = op.label;
	else if (arg_type[i] == T_IND)
		length = IND_SIZE;//здесь по ходу нужно кастить!!!!
	return (length);
}

int				*extract_arg(t_op op, int pc, t_arg_type *arg_type)//ПРИ СЧИТЫВАНИИ АРГУМЕНТЫ НУЖНО КАСТИТЬ!
{
	int				i;
	int				length;
	int				pc_copy;
	int				*arg;
	unsigned char	*line;

	i = 0;
	length = 0;
	pc_copy = pc;
	pc = op.codage ? pc + 2 : pc + 1;
	arg = (int *)malloc(sizeof(int) * op.arg_num);//if !line malloc failed
	line = NULL;
	while (i < op.arg_num)
	{
		length = arg_type ? get_length(arg_type[i]) : op.label;
		line = extract_line(&pc, length, MEM_SIZE);//под вопросом
		arg[i] = conv_hex(line, length);
		if (arg_type[i] == T_IND)
			arg[i] = extract_ind(pc_copy, arg[i]);
		free(line);
		i++;
		pc += length;//???
	}
	return (arg);
}

unsigned char	*extract_line(int pc, int length, int base)//здесь еще нужно учесть, что мо
{
	int 			i;
	unsigned char	*line;

	i = 0;
	pc = pc % base;
	line = (unsigned char *)malloc(sizeof(unsigned char) * length);//if !line malloc failed
	while (i < length)
	{
		line[i] = g_game.board[pc];
		i++;
		pc = (pc + 1) % base;
	}
	return (line);
}

int				extract_ind(int pc, int delta)//maybe I also need to have base here
{
	unsigned char	*line;
	int				res;

	res = 0;
	line = extract_line(pc + delta, 4, IDX_MOD);//maybe dif here? depending on opcode?
	res = conv_hex(line, 4);
	free(line);
	return (res);		
}

// unsigned char	*extract_line(int *pc, int length)
// {
// 	int 			new_pc;
// 	int 			i;
// 	unsigned char	*line;

// 	i = 0;
// 	new_pc = *pc;
// 	line = (unsigned char *)malloc(sizeof(unsigned char) * length);//if !line malloc failed
// 	while (i < length)
// 	{
// 		new_pc = (new_pc + 1) % MEM_SIZE;
// 		line[i] = g_game.board[new_pc];
// 		i++;
// 	}
// 	*pc = new_pc;
// 	return (line);
// }

