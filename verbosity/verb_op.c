/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verb_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:47:33 by dgonor            #+#    #+#             */
/*   Updated: 2018/07/20 16:47:35 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbosity.h"

static int 			*verb_arg_arr(unsigned int *arg, int num)
{
	int 	*new;
	int 	i;

	i = -1;
	new = NULL;
	if (!(new = (int*)malloc(sizeof(int) * num)))
		return (NULL);
	while (++i < num)
		new[i] = arg[i];
	return (new);
}

static t_arg_type 		*verb_arg_type(int num, t_arg_type *arg_type)
{
	t_arg_type 	*new;
	int 	i;

	i = -1;
	if (!(new = (t_arg_type*)malloc(sizeof(t_arg_type) * (num + 1))))
		return (NULL);
	while (++i < num)
		new[i] = arg_type[i];
	return (new);
}

static void			verb_lstback_op(t_list_op **lst, t_list_op *add)
{
	t_list_op	*tmp;

	if (lst && *lst && add)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add;
	}
}

static t_list_op		*verb_create_process(t_process *proc, t_arg_type *arg_type, unsigned int *arg)
{
	t_list_op	*new;

	if (!(new = (t_list_op*)malloc(sizeof(t_list_op) * 1)))
		return (NULL);
	new->proc_num = proc->num;
	new->opcode = proc->opcode;
	new->arg_num = op_tab[proc->opcode -1].arg_num;
	new->arg = verb_arg_arr(arg, new->arg_num);
	new->arg_type = verb_arg_type(new->arg_num, arg_type);
	new->next = NULL;
	return (new);
}

void	verb_add_op(t_process *proc, t_arg_type *arg_type, unsigned int *arg)
{
// 		arg_type и arg нужно копировать!!! маллок

//		P    1 | live -1
// 		Player 1 (zork) is said to be alive//show lives ??

//		P    1 | sti r1 15 1
//				| -> store to 15 + 1 = 16 (with pc and mod 16)
	if (!g_verb.op)
		g_verb.op = verb_create_process(proc, arg_type, arg);
	else
		verb_lstback_op(&g_verb.op, verb_create_process(proc, arg_type, arg));
}