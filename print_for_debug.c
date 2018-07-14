#include "corewar.h"

void		print_proc(t_process *proc)//del
{
	t_process	*tmp;
	int 		i;

	tmp = proc;
	i = -1;
	while (tmp)
	{
		ft_printf("player = %i\n", tmp->player);
		ft_printf("carry = %i\n", tmp->carry);
		ft_printf("pc = %i\n", tmp->pc);
		ft_printf("cycles_to_exec = %i\n", tmp->cycles_to_exec);
		ft_printf("opcode = %i\n", tmp->opcode);
		while (++i < REG_NUMBER)
			ft_printf("%i ", tmp->reg[i]);
		ft_printf("\n");
		tmp = tmp->next;
		i = -1;
	}
}

void	print_champ(t_lst_champs *champ)//del
{
	unsigned int i;
	
	i = 0;
	ft_printf("name = |%s|\n", champ->name);
	ft_printf("magic = %#x\n", champ->magic);
	ft_printf("comment = |%s|\n", champ->comment);
	ft_printf("size = |%u|\n", champ->size);
	while (i < champ->size)
	{
		ft_printf("%02x ", champ->comms[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_players(t_player *player)
{
	int i = 0;
	while (i < g_game.players)
	{
		ft_printf("num = %i  start = %i name = %s\n", i + 1, player[i].start, player[i].name);
		ft_printf("comment = %s\n", player[i].comment);
		i++;
	}
}
