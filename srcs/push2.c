/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:25:58 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 19:09:54 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(t_stack *st)
{
	t_list	*list;
	int		min;

	min = st->top->data->index;
	list = st->top;
	st->top = st->top->next;
	while (st->top)
	{
		if (min > st->top->data->index)
			min = st->top->data->index;
		st->top = st->top->next;
	}
	st->top = list;
	return (min);
}

int		max(t_stack *st)
{
	t_list	*list;
	int		max;

	max = st->top->data->index;
	list = st->top;
	st->top = st->top->next;
	while (st->top)
	{
		if (max < st->top->data->index)
			max = st->top->data->index;
		st->top = st->top->next;
	}
	st->top = list;
	return (max);
}

void	give_order_keys(t_list *list)
{
	t_list *i;
	t_list *j;

	i = list;
	while (list)
	{
		j = i;
		while (j)
		{
			if (j->data->val < list->data->val)
				list->data->index++;
			j = j->next;
		}
		list = list->next;
	}
}

int		is_need_sorted(t_stack *st)
{
	t_list *list;

	list = st->top;
	if (st->top == NULL)
		return (0);
	while (st->top->next)
	{
		if (st->top->data->val > st->top->next->data->val)
		{
			st->top = list;
			return (0);
		}
		st->top = st->top->next;
	}
	st->top = list;
	return (1);
}
