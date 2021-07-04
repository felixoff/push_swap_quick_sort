/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:25:58 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 19:32:59 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *st)
{
	int i;

	if (st->top != NULL && st->size > 1)
	{
		i = st->top->data->val;
		st->top->data->val = st->top->next->data->val;
		st->top->next->data->val = i;
		i = st->top->data->index;
		st->top->data->index = st->top->next->data->index;
		st->top->next->data->index = i;
	}
}

void	stack_push(t_stack **a, t_stack **b)
{
	t_data	*list;

	if ((*b)->top != NULL)
	{
		pop(b, &list);
		push(a, list->val, list->index);
		free(list);
	}
}

void	rotate(t_stack **st)
{
	t_list	*list;
	t_data	*data;

	if ((*st)->top != NULL && (*st)->size > 1)
	{
		list = (*st)->top;
		data = (*st)->top->data;
		while ((*st)->top->next != NULL)
		{
			(*st)->top->data = (*st)->top->next->data;
			(*st)->top = (*st)->top->next;
		}
		(*st)->top->data = data;
		(*st)->top = list;
	}
}

t_data	*get_last_elem(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list->data);
}

void	reverse_rotate(t_stack *st)
{
	t_data *data1;
	t_data *data2;
	t_list *list;

	data1 = NULL;
	data2 = NULL;
	if (st->top != NULL && st->size > 1)
	{
		list = st->top;
		data2 = st->top->data;
		st->top->data = get_last_elem(st->top);
		st->top = st->top->next;
		while (st->top)
		{
			data1 = st->top->data;
			st->top->data = data2;
			data2 = data1;
			st->top = st->top->next;
		}
		st->top = list;
	}
}
