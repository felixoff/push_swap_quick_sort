/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:25:58 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 19:10:39 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacks **stacks)
{
	quick_sort2(stacks, (*stacks)->a->size - 2);
}

void	quick_sort2(t_stacks **stacks, size_t kol)
{
	int mas[2];

	mas[0] = 0;
	mas[1] = 0;
	if ((*stacks)->a->size > 5)
		mas[0] = (*stacks)->a->size - 5;
	if ((*stacks)->a->size > 3)
	{
		while ((*stacks)->a->size > kol)
		{
			if ((*stacks)->a->top->data->index <
			((min((*stacks)->a) + max((*stacks)->a) - mas[0]) / 2))
			{
				exec_print(stacks, "pb");
				mas[1]++;
			}
			else if ((*stacks)->a->size > kol)
				exec_print(stacks, "ra");
		}
		quick_sort2(stacks, kol - 2);
		while (mas[1]--)
			exec_print(stacks, "pa");
	}
	quick_sort3((*stacks)->a, stacks);
}

void	quick_sort3(t_stack *st, t_stacks **stacks)
{
	if ((st->top->data->index - st->top->next->data->index) == 1
	|| (st->top->data->index - st->top->next->data->index) == -2)
		exec_print(stacks, "sa");
	if ((st->top->data->index - st->top->next->data->index) == -1
	&& !is_need_sorted(st))
		exec_print(stacks, "rra");
	if ((st->top->data->index - st->top->next->data->index) == 2
	&& !is_need_sorted(st))
		exec_print(stacks, "ra");
}

void	exec_print(t_stacks **stacks, char *str)
{
	execution2(&(*stacks)->a, &(*stacks)->b, str);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
