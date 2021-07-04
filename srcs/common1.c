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

void	execution2(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "sa"))
		swap(*a);
	else if (!ft_strcmp(s, "sb"))
		swap(*b);
	else if (!ft_strcmp(s, "ss"))
		swap2(*a, *b);
	else if (!ft_strcmp(s, "pa"))
		stack_push(a, b);
	else if (!ft_strcmp(s, "pb"))
		stack_push(b, a);
	else if (!ft_strcmp(s, "ra"))
		rotate(a);
	else if (!ft_strcmp(s, "rb"))
		rotate(b);
	else if (!ft_strcmp(s, "rr"))
		rotate2(*a, *b);
	else if (!ft_strcmp(s, "rra"))
		reverse_rotate(*a);
	else if (!ft_strcmp(s, "rrb"))
		reverse_rotate(*b);
	else if (!ft_strcmp(s, "rrr"))
		reverse_rotate2(*a, *b);
}

void	is_executeable(char *s)
{
	if (ft_strcmp(s, "sa") && ft_strcmp(s, "sb") && ft_strcmp(s, "ss")
		&& ft_strcmp(s, "pa") && ft_strcmp(s, "pb") && ft_strcmp(s, "ra")
		&& ft_strcmp(s, "rb") && ft_strcmp(s, "rr") && ft_strcmp(s, "rra")
		&& ft_strcmp(s, "rrb") && ft_strcmp(s, "rrr"))
		fail("Неверная комманда");
}

char	*ft_strcpy(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int		ft_strcmp(char *s1, char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	execution(t_stacks **stacks)
{
	char	*str;
	size_t	size;

	is_uni((*stacks)->a->top);
	if ((*stacks)->visual == 1)
		write(1, "> ", 2);
	while ((size = get_next_line(0, &str)) > 0)
	{
		is_executeable(str);
		execution2(&((*stacks)->a), &((*stacks)->b), str);
		free(str);
	}
	is_stacks(stacks);
}
