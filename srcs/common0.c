/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:25:58 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 19:53:48 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **st, int data, int index)
{
	t_list *list;

	init_list(&list);
	init_data(&list->data);
	if (list)
	{
		list->data->val = data;
		list->data->index = index;
		list->next = (*st)->top;
		(*st)->top = list;
		(*st)->size++;
	}
}

void	clean_stacks(t_stacks **stacks)
{
	clean_list(&((*stacks)->a->top));
	clean_list(&((*stacks)->b->top));
	free((*stacks)->a);
	free((*stacks)->b);
	free(*stacks);
}

void	init_stacks(t_stacks **stacks, int size)
{
	if (!((*stacks) = malloc(sizeof(t_stacks))))
		fail("Ошибка маллока");
	if (!((*stacks)->a = malloc(sizeof(t_stack))))
		fail("Ошибка маллока");
	(*stacks)->a->top = NULL;
	(*stacks)->a->size = 0;
	if (!((*stacks)->b = malloc(sizeof(t_stack))))
		fail("Ошибка маллока");
	(*stacks)->b->top = NULL;
	(*stacks)->b->size = 0;
	(*stacks)->issort = 0;
	(*stacks)->lenght = size;
}

void	is_int(char **str)
{
	long	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[j])
	{
		k = 0;
		while (str[j][k])
		{
			if (str[j][k] > '9' || str[j][k] < '0')
				if (str[j][k] != '-' && str[j][k] != '+')
					fail("Ошибка введенного числа");
			k++;
		}
		i = ft_atoi(str[j]);
		if (i > -32768 && i < 32767)
			j++;
		else
			fail("Ошибка введенного числа");
	}
}
