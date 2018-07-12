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
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include "op.h"
# include "./libft/libft.h"
# define HEX "0123456789abcdef"

extern char				*g_usage[19];
extern char				*g_error[16];

typedef struct			s_change
{
	int					player;
	unsigned char		value;
	unsigned int		pos;
	struct s_change		*next;
}						t_change;

typedef struct			s_process
{
	int					player;
}						t_process;

typedef	struct			s_player
{
	char				*name;
	char				*comment;
	unsigned char		*comms;
	int					start;
	unsigned int		len;
	int					last_live;
	int					lives_in_curr;
}						t_player;

typedef struct			s_lst_champs
{
	int					num;
	int					error;
	bool				n_flag;
	char				*file_name;//no malloc
	int					fd;
	unsigned int		magic;
	unsigned int		size;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		*comms;//instructions
	struct s_lst_champs	*next;//no malloc
}						t_lst_champs;

typedef	struct			s_parse
{
	int					players;
	t_lst_champs		*champ;
	bool				dump;
	bool				visu;
	bool				v;
	int					nbr_cycles;
	int					nbr_cycles_visu;
	int					number_v;
}						t_parse;

t_parse					g_game;
void					usage(void);
void					error(int num);
void					parse_args(int argc, char **argv);
void					validate_dump(int argc, char **argv, int *i);
bool					validate_num(char *str);
bool					check_if_int(char *str);
void					validate_visu(int argc, char **argv, int *i);
void					validate_verbal(int argc, char **argv, int *i);
void					validate_champ(int argc, char **argv, int *i);
int						validate_champ_num(int argc, char **argv, int *i);
void					check_double_positions(int num);
void					champ_position(t_lst_champs *champ, int num);
t_lst_champs			*new_champ(char *file_name, int num, bool n_flag);
void					add_champ(t_lst_champs **head, t_lst_champs *new);
void					set_blank_positions(void);
void					check_positions(void);
void					sort_champs(void);
t_lst_champs			*swap_champs(t_lst_champs *tmp, t_lst_champs *prev);
void					parse_champs(void);
void					read_champs_info(t_lst_champs *champ);
unsigned int			read_num(t_lst_champs *champ, int len);
void					read_string(t_lst_champs *champ, char *line, int len);
void					read_instructions(t_lst_champs *champ);
unsigned int			conv_hex(unsigned char *line, int length);
char					*ft_strljoin(char **s1, char **s2);
char					*hex_line(unsigned char *line, int length);
unsigned int			ft_atoi_base(char *str, long long base);
void					print_champ(t_lst_champs *champ);//del
void					start_game(void);
t_player				*create_players(void);
#endif
