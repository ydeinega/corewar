/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:14:05 by ydeineha          #+#    #+#             */
/*   Updated: 2018/07/04 14:14:07 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_champs(void)
{
	read_champs();
}

void	read_champs(void)
{
	t_lst_champs	*tmp;
	int				fd;//
	unsigned char	line[5000];//memset
	char			*ptr;
	int				ret;

	//line = NULL;
	tmp = g_game.champ;
	ptr = NULL;
	fd = open("test", O_CREAT | O_WRONLY, S_IRWXU);
	while (tmp)
	{
		ft_printf("file_name = |%s|\n", tmp->file_name);
		if ((tmp->fd = open(tmp->file_name, O_RDONLY)) == -1)
		{
			perror("open() ");
			error(-1);
		}
		ret = read(tmp->fd, line, 5000);
		if (ret == -1)
			perror("read() ");
		line[ret] = '\0';

		int i;
		int check;
		
		i = 0;
		check = 0;
		while (i < ret)
		{
			ft_printf("%02X ", line[i]);
			check++;
			i++;
			if (check == 32)
			{
				ft_printf("\n");
				check = 0;
			}
		}
		//ret = get_next_line(tmp->fd, &line);


		// while (get_next_line(tmp->fd, &line))
		// {
		// 	if (tmp->file_cont)
		// 	{

		// 	}
		// }
		//ft_printf("%s\n", tmp->file_cont);
		//ft_printf("fd = %d ret = %d ft_strlen = %d\n", tmp->fd, ret, ft_strlen(line));
		//ft_printf("fd = %d ret = %d ft_strlen_u = %d\n", tmp->fd, ret, ft_strlen_u(line));
		//ft_putstr_fd(line, fd);
		tmp = tmp->next;
	}
}