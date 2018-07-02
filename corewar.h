/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:41:59 by ydeineha          #+#    #+#             */
/*   Updated: 2018/06/27 19:42:02 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <stdbool.h>
# include "op.h"
# include "./libft/libft.h"

extern char			*g_usage[7];
extern char			*g_error[10];

typedef struct			s_process
{
	int					player;
}						t_process;

typedef	struct			s_player
{
	char				*name;
	char				*comment;
	int					start;
	int					length;
	int					last_live;
	int					lives_in_curr;
}						t_player;

typedef struct			s_lst_champs
{
	int					num;
	bool				n_flag;
	char				*file_name;//no malloc
	int					fd;
	char				*file_cont;
	unsigned int		file_size;
	unsigned int		magic;
	char				*name;
	char				*comment;
	char				*instruct;
	struct s_lst_champs	*next;//no malloc
}						t_lst_champs;

typedef	struct			s_parse
{
	int					players;
	t_lst_champs		*champ;
	bool				dump;
	bool				visu;
	int					nbr_cycles;
}						t_parse;

t_parse					g_game;
void					usage(void);
void					error(int num);
void					parse_args(int argc, char **argv);
void					validate_dump(int argc, char **argv, int *i);
bool					validate_num(char *str);
bool					check_if_int(char *str);
void					validate_champ(int argc, char **argv, int *i);
int						validate_champ_num(int argc, char **argv, int *i);
void					check_double_positions(int num);
void					champ_position(t_lst_champs *champ, int num);
t_lst_champs			*new_champ(char *file_name, int num, bool n_flag);
void					add_champ(t_lst_champs **head, t_lst_champs *new);
void					set_positions(void);
#endif
