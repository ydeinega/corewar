/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:03:34 by ydeineha          #+#    #+#             */
/*   Updated: 2018/06/30 15:03:38 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

bool	validate_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (!check_if_int(str))
		return (false);
	return (true);
}

bool	check_if_int(char *str)
{
	char	*s;
	int		len;
	int		i;

	i = -1;
	s = "2147483647";
	len = ft_strlen(str);
	if (len < 10 || len > 10)
		return (len < 10);
	else if (len == 10)
	{
		while (str[++i])
		{
			if (str[i] < s[i])
				return (true);
			if (str[i] > s[i])
				return (false);
		}
	}
	return (1);
}

void	validate_dump(int argc, char **argv, int *i)
{
	if (g_game.dump == true)
		error(0);
	if (*i + 1 == argc)
		error(1);
	g_game.dump = true;
	*i += 1;
	if (!validate_num(argv[*i]))
		error(1);
	g_game.nbr_cycles = ft_atoi(argv[*i]);
}

void	champ_position(t_lst_champs champ, int num)
{
	t_lst_champs	*tmp;

	tmp = g_game.champ;
	while (tmp)
	{
		if (tmp->num == num)
			change_champ_position(tmp, num + 1);
		tmp = tmp->next;
	}
	champ->num = num;
}

void	check_champ_positions(int num)
{
	t_lst_champs	*tmp;

	tmp = g_game.champ;
	while (tmp)
	{
		if (tmp->num == num && tmp->n_flag == true)
			error(5);
		else if (tmp->num == num && tmp->n_flag == false)
			champ_position(tmp, 1);
		tmp = tmp->next;
	}
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
	!num || num > 4 ? error(3) : 0;
	g_game.champ ? check_champ_positions(num);
	return (num);
}

void	add_champ(t_lst_champs **head, t_lst_champs new)
{
	if (head && new)
	{
		if (*head)
		{
			new->next = *head;
			*head = new;
		}
		else
			*head = new;
	}
}

t_lst_champs	*new_champ(char *file_name, int num, bool n_flag)
{
	t_lst_champs	*champ;

	champ = (t_lst_champs *)malloc(sizeof(t_lst_champs));
	if (!champ)
		return (NULL);
	champ->file_name = file_name;
	champ->num = num;
	champ->n_flag = n_flag;
	champ->fd = 0;
	champ->file_cont = NULL;
	champ->file_size = 0;
	champ_magic = 0;
	champ_name = NULL;
	champ_comment = NULL;
	champ_instuct = NULL;
	champ->next = NULL;
	return (champ);
}

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
		if (!num)
			champ_position(new, 1);
		add_champ(&(g_game->champ), new);
		//возможно, здесь нужно валидировать имя программы
		//в хедер файле задефайнены макс размеры програм_нейм, коммента и мэджик намбер ПОТЕСТИТЬ
	}
	else
		error(4);

}


void	parse_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-dump"))
			validate_dump(argc, argv, &i);
		else if (ft_strequ(argv[i], "-visu"))
			g_game.visu = true;
		else if (ft_strequ(argv[i], "-n") || ft_strstr(argv[i], ".cor"))
		{
			g_game.players == 4 ? error(6) : 0;
			g_game.players += 1;
			validate_champ(argc, argv, &i);
		}
		else
			error(0);
		i++;
	}
	//после парсинга аргументов проверить кол-во чемпионов
	//если ни визу, ни дамп не включены что делать? - просто пишем кто победил и все?
	//проверить одневременную включенность визу и дампа
}
