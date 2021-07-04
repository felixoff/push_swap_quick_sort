/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:25:58 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 18:50:22 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack **st, t_data **list)
{
	t_list	*list2;

	if ((*st)->top)
	{
		list2 = (*st)->top;
		(*st)->size--;
		(*st)->top = (*st)->top->next;
		*list = list2->data;
		free(list2);
	}
}

void	init_list(t_list **list)
{
	if (!((*list) = malloc(sizeof(t_list))))
		fail("Ошибка маллока");
	(*list)->data = NULL;
}

void	init_data(t_data **data)
{
	if (!((*data) = malloc(sizeof(t_data))))
		fail("Ошибка маллока");
	(*data)->val = 0;
	(*data)->index = 0;
}

void	clean_data(t_list *list)
{
	t_list		*list1;
	t_list		*list2;

	list1 = list;
	while (list1 != NULL)
	{
		list2 = list1;
		list1 = list1->next;
		free(list2->data);
	}
}

void	clean_list(t_list **top)
{
	t_list	*list;
	t_list	*next;

	list = *top;
	while (list)
	{
		next = list->next;
		free(list->data);
		free(list);
		list = next;
	}
	*top = NULL;
}
