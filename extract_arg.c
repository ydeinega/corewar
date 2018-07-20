#include "corewar.h"

static int				get_length(t_arg_type arg_type, t_op op)
{
	int	length;

	length = 0;
	if (arg_type == T_REG)
		length = 1;
	else if (arg_type == T_DIR)
		length = op.label;
	else if (arg_type == T_IND)
		length = IND_SIZE;
	return (length);
}

unsigned int			extract_ind(int pc, int delta)//BASE???
{
	unsigned char	*line;
	unsigned int	res;

	res = 0;
	line = extract_line(pc + delta, 4, IDX_MOD);//maybe dif here? depending on opcode?
	res = conv_hex(line, 4);
	free(line);
	return (res);		
}

static unsigned int		get_arg(t_op op, t_arg_type arg_type, unsigned int res, int pc)
{
	if (arg_type == T_REG)
		res = (unsigned int)((unsigned char)res);
	else if (arg_type == T_DIR && op.label == 2)
		res = (unsigned int)((short)res);
	else if (arg_type == T_IND)
		res = extract_ind(pc, res);
	return (res);
}

unsigned int			*extract_arg(t_op op, int pc, t_arg_type *arg_type)//ПРИ СЧИТЫВАНИИ АРГУМЕНТЫ НУЖНО КАСТИТЬ!
{
	int				i;
	int				length;
	int				pc_copy;
	unsigned int	*arg;
	unsigned char	*line;

	i = 0;
	length = 0;
	pc_copy = pc;
	pc = op.codage ? pc + 2 : pc + 1;
	arg = (unsigned int *)malloc(sizeof(unsigned int) * op.arg_num);//if !line malloc failed
	line = NULL;
	while (i < op.arg_num)
	{
		if (!arg_type)
			ft_printf("arg_type is null\n");
		length = arg_type ? get_length(arg_type[i], op) : op.label;
		line = extract_line(pc, length, MEM_SIZE);//под вопросом
		if (arg_type)
			arg[i] = get_arg(op, arg_type[i], conv_hex(line, length), pc_copy);
		else
			arg[i] = get_arg(op, op.arg[0], conv_hex(line, length), pc_copy);
		free(line);
		i++;
		pc += length;//???
	}
	return (arg);
}

unsigned char		*extract_line(int pc, int length, int base)
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

