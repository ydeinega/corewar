#ifndef VERBOSITY_H
# define VERBOSITY_H
# include "corewar.h"

typedef struct			s_list_pc
{
	int					start;
	int					dest;
	struct s_list_op	*next;
}						t_list_pc;

typedef struct			s_list_op
{
	int					opcode;
	struct s_list_op	*next;
}						t_list_op;

typedef struct			s_list_death
{
	int					proc;
	int					cycles_not_live;
	struct s_list_op	*next;
}						t_list_death;

typedef struct 			s_verb
{
	int					cycle;//их можно сделать указателями
	int					ctd;//их можно сделать указателями
	t_list_op			*op;
	t_list_pc			*pc;
	t_list_death		*death;
}						t_verb;

t_verb					g_verb;
void					verb_mode(int number_v);
void					introduce_contestants();

#endif
