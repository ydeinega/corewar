#include "corewar.h"

int			find_start(int i)
{
	int rows;
	int	res;

	res = 0;
	rows = (MEM_SIZE / 32) / g_game.players;
	res = rows * (i - 1) * 32;
	return (res);
}

t_player	*create_players(void)
{
	t_player		*player;
	t_lst_champs	*tmp;
	int				i;

	i = -1;
	if (!(player = (t_player *)malloc(sizeof(t_player) * g_game.players)))
	{
		perror("malloc() in create_players() failed ");
		error(-1);
	}
	while (++i < g_game.players)
	{
		tmp = g_game.champ;
		player[i].name = tmp->name;
		player[i].comment = tmp->comment;
		player[i].comms = tmp->comms;
		player[i].len = tmp->size;
		player[i].start = find_start(i + 1);
		player[i].last_live = 0;
		player[i].lives_in_curr = 0;
		g_game.champ = g_game.champ->next;
		free(tmp);
	}
	return (player);
}

unsigned char	*create_board(t_player *player)
{
	unsigned char	*board;
	int				i;

	i = -1;
	if (!(board = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE)))
	{
		perror("malloc() in create_board() failed ");
		error(-1);
	}
	board = ft_memset(board, 0, MEM_SIZE);
	while (++i < g_game.players)
		ft_memcpy(&board[player[i].start], player[i].comms, player[i].len);
	return (board);
}

void		dump(unsigned char *board)
{
	int i;
	int	new_line;

	i = -1;
	new_line = 0;
	while (++i < MEM_SIZE)
	{
		ft_printf("%02x ", board[i]);
		new_line++;
		if (new_line == 32)
		{
			ft_printf("\n");
			new_line = 0;
		}
	}
}

void		start_game(void)
{
	t_player		*player;
	unsigned char	*board;

	player = create_players();
	board = create_board(player);
	dump(board);
	// int i = 0;
	// while (i < g_game.players)
	// {
	// 	ft_printf("num = %i  start = %i name = %s\n", i + 1, player[i].start, player[i].name);
	// 	ft_printf("comment = %s\n", player[i].comment);
	// 	i++;
	// }
}