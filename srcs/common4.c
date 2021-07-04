/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:25:58 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 19:29:32 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap2(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate2(t_stack *a, t_stack *b)
{
	rotate(&a);
	rotate(&b);
}

void	reverse_rotate2(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
