/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:30:41 by ydeineha          #+#    #+#             */
/*   Updated: 2018/07/02 16:30:43 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	validate_champ(int argc, char **argv, int *i)
{
	int 			num;
	t_lst_champs	*new;

	num = 0;
	new = NULL;
	if (ft_strequ(argv[*i], "-n"))
		num = validate_champ_num(argc, argv, i);
	if (ft_strstr(argv[*i], ".cor"))
	{
		new = num > 0 ? new_champ(argv[*i], num, true) :
		new_champ(argv[*i], num, false);
		// if (!num)
		// 	champ_position(new, 1);
		add_champ(&(g_game.champ), new);
		g_game.players += 1;
		//возможно, здесь нужно валидировать имя программы
		//в хедер файле задефайнены макс размеры програм_нейм, коммента и мэджик намбер ПОТЕСТИТЬ
	}
	else
		error(4);

}

int		validate_champ_num(int argc, char **argv, int *i)
{
	int num;

	num = 0;
	if (*i + 1 == argc)
		error(2);
	else if (*i + 2 >= argc)
	{
		if (ft_strstr(argv[*i + 1], ".cor"))
			error(2);
		else if (validate_num(argv[*i + 1]))
			error(4);
		else
			error(2);
	}
	else
	{
		*i += 2;
		if (validate_num(argv[*i - 1]))
			num = ft_atoi(argv[*i - 1]);
		else	
			error(2);
	}
	!num || num > MAX_PLAYERS ? error(3) : 0;//использую дефайн из op.h
	g_game.champ ? check_double_positions(num) : 0;
	return (num);
}

void	check_double_positions(int num)
{
	t_lst_champs	*tmp;

	tmp = g_game.champ;
	while (tmp)
	{
		if (tmp->num == num && tmp->n_flag == true)
			error(5);
		// else if (tmp->num == num && tmp->n_flag == false)
		// 	champ_position(tmp, 1);
		tmp = tmp->next;
	}
}

//Все еще вопрос, как нумеровать чемпионов??? от 1 до 4 или от 4 до 1-го???
void	champ_position(t_lst_champs *champ, int num)
{
	t_lst_champs	*tmp;
	int				check;

	check = 0;
	tmp = g_game.champ;
	while (tmp)
	{
		if (tmp->num == num)
		{
			check++;
			num--;
		}
		tmp = !check ? tmp->next : g_game.champ;
		check = 0;
	}
	champ->num = num;
}
