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
			g_game.players == MAX_PLAYERS ? error(6) : 0;//op.h
			validate_champ(argc, argv, &i);
		}
		else
			error(0);
		i++;
	}
	if (!g_game.players)
		error(4);
	set_blank_positions();
	check_positions();
	//вопрос нумерации остается открытым
	//проверить пропуски в нумерации. Не может быть 2 аргумента с нумерацией 1 и 3
	//проверить пропуски можно 2-мя способами
	// 1 - это на этапе создания массива
	// 2 - это сортировка элементов и итерация

	ft_printf("Players\n");
	t_lst_champs *tmp = g_game.champ;
	while (tmp)
	{
		ft_printf("file = %s num = %d\n", tmp->file_name, tmp->num);
		tmp = tmp->next;
	}
	//если ни визу, ни дамп не включены что делать? - просто пишем кто победил и все?
	//проверить одневременную включенность визу и дампа
}
