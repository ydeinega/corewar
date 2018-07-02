/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:06:13 by ydeineha          #+#    #+#             */
/*   Updated: 2018/06/30 15:06:15 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	char	*g_usage[7] =
**	{
**	0	"Usage: ./corewar",
**	1	"-dump nbr_cycles",
**	2	"Dumps memory after nbr_cycles and exits",
**	3	"-n number",
**	4	"Sets the number of the next player",
**	5	"-visu",
**	6	"Ncurses output mode"
**	}
*/

/*
**	char	*g_error[10] =
**	{
**	0		"invalid argument",
** 	1		"argument nbr_cycles is invalid or missing\n"
**			"Nbr_cycles argument is needed after -dump",
**	2		"argument number is invalid or missing\n"
**			"Number argument is needed after -n",
**	3		"number argument must be in the range from 1 to 4",
**	4		"champion is missing",
**	5		"champions cannot have same numbers",
**	6		"too many players. Max number of champions is 4"
**	};
*/

char	*g_usage[7] =
{
	"Usage: ./corewar",
	"-dump nbr_cycles",
	"Dumps memory after nbr_cycles and exits",
	"-n number",
	"Sets the number of the next player",
	"-visu",
	"Ncurses ouptut mode"
};

char	*g_error[10] =
{
	"invalid argument",
	"argument nbr_cycles is invalid or missing\n"
	"Nbr_cycles argument is needed after -dump",
	"argument number is invalid or missing\n"
	"Number argument is needed after -n",
	"number argument must be in the range from 1 to 4",
	"champion is missing",
	"champions cannot have same numbers",
	"too many players. Max number of champions is 4"
};

void	usage(void)
{
	ft_printf("%s [%s] [%s] [[%s] champion1.cor] ...\n",
			g_usage[0], g_usage[1], g_usage[5], g_usage[3]);
	ft_printf("%5c%-20s: %s\n", ' ', g_usage[1], g_usage[2]);
	ft_printf("%5c%-20s: %s\n", ' ', g_usage[5], g_usage[6]);
	ft_printf("%5c%-20s: %s\n", ' ', g_usage[3], g_usage[4]);
	exit(1);
}

void	error(int num)
{
	//clear_game
	ft_printf("ERROR");
	if (num >= 0)
		ft_printf(": %s", g_error[num]);
	ft_printf("\n");
	exit(1);
}
