#include "corewar.h"

// static int 		digits_num(unsigned int num, unsigned int base)
// {
// 	int n;

// 	n = 1;
// 	while (num / base > 0)
// 	{
// 		n++;
// 		num = num / base;
// 	}
// 	return (n);
// }

void	store_value(t_process *proc, unsigned int value, int delta, int base)
{
	int				index;
	unsigned char	*str;
	int				i;
	int				len;

	i = 0;
	str = to_hex_str(value, 16);
	len = 4;//here I can use define??
	index = (proc->pc + (delta % base)) % MEM_SIZE;//???
	while (i < len)
	{
		g_game.board[index] = str[i];
		i++;
		index = (index + i) % MEM_SIZE;//or base???
	}
}

unsigned char	*to_hex_str(unsigned int num, unsigned int base)
{
	int					n;
	unsigned int		mod;
	unsigned char		*str;

	n = 4;//here I can use define??
	str = (unsigned char *)malloc(sizeof(unsigned char) * 4);//if !str malloc failed
	ft_memset(str, 0, 4);
	if (!str)
		return (NULL);
	n--;
	while (n >= 0)
	{
		mod = num % base;
		str[n] = (unsigned char)mod;
		n--;
		num = num / base;
	}
	return (str);
}
