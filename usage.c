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
**	char	*g_usage[19] =
**	{
**	0	"Usage: ./corewar",
**	1	"-n number",
**	2	"Sets the number of the next player",
**	3	"-a",
**	4	"Prints output from "aff" (Default is to hide it)",
**	5	"#### TEXT OUTPUT MODE "
		"##########################################################",
**	6	"-dump nbr_cycles",
**	7	"Dumps memory after nbr_cycles and exits",
**	8	"-v number",
**	9	"Verbosity levels, can be added together to enable several",
**	10	"- 0 : Show only essentials",
**	11	"- 1 : Show lives",
**	12	"- 2 : Show cycles",
**	13	"- 4 : Show operations (Params are NOT litteral ...)",
**	14	"- 8 : Show deaths",
**	15	"-16 : Show PC movements (Except for jumps)",
**	16	"#### NCURSES OUTPUT MODE "
**		"#######################################################",
**	17	"-visu",
**	18	"Ncurses ouptut mode"
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
**	3		"number argument must be in the range from 1 to (MAX_PLAYERS)",
**	4		"champion is missing",
**	5		"champions cannot have same numbers",
**	6		"too many players. Max number of champions is (MAX_PLAYERS)",
**	7		"numbering value inconsistent"
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
	"number argument must be in the range from 1 to ",
	"champion is missing",
	"champions cannot have same numbers",
	"too many players. Max number of champions is ",
	"numbering value inconsistent"
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
	//clean_game
	ft_printf("ERROR");
	if (num >= 0)
		ft_printf(": %s", g_error[num]);
	if (num == 6 || num == 3)
		ft_printf("%d", MAX_PLAYERS);
	ft_printf("\n");
	exit(1);
}
