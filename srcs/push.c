/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:25:58 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 19:13:19 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**str;
	int			i;

	if (argc > 1)
	{
		init_stacks(&stacks, argc - 1);
		while (--argc > 0)
		{
			i = 0;
			str = ft_split(argv[argc], ' ');
			while (str[i + 1])
				i++;
			is_int(str);
			while (i > -1)
				push(&stacks->a, ft_atoi(str[i--]), 0);
			free_str(&str);
		}
		is_uni(stacks->a->top);
		give_order_keys(stacks->a->top);
		if (!is_need_sorted(stacks->a))
			quick_sort(&stacks);
		clean_stacks(&stacks);
	}
	return (0);
}
