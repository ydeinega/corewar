/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:32:55 by ydeineha          #+#    #+#             */
/*   Updated: 2018/07/02 16:32:57 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

void			add_champ(t_lst_champs **head, t_lst_champs new)
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
