/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:25:58 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 19:20:29 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char ***str)
{
	char **tmp;

	tmp = *str;
	if (*str)
	{
		while (*tmp)
			free(*tmp--);
		free(*str);
	}
	str = NULL;
}

void	fail(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

void	is_stacks(t_stacks **stacks)
{
	t_list *list;

	list = (*stacks)->a->top;
	if ((*stacks)->a->size == 0 || (*stacks)->b->size != 0)
		fail("KO");
	while ((*stacks)->a->top->next)
	{
		if ((*stacks)->a->top->data->val > (*stacks)->a->top->next->data->val)
			fail("KO");
		(*stacks)->a->top = (*stacks)->a->top->next;
	}
	(*stacks)->a->top = list;
	write(1, "OK", 2);
	write(1, "\n", 1);
}

void	is_uni(t_list *a)
{
	t_list *list;

	while (a->next != NULL)
	{
		list = a->next;
		while (list != NULL)
		{
			if (list->data->val == a->data->val)
				fail("Повторяющийся символ");
			list = list->next;
		}
		a = a->next;
	}
}
