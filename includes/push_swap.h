/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:39:49 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 18:42:47 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <errno.h>

typedef struct	s_data {
	int			val;
	int			index;
}				t_data;

typedef struct	s_list {
	t_data			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_stack {
	t_list		*top;
	size_t		size;
}				t_stack;

typedef struct	s_stacks {
	t_stack		*a;
	t_stack		*b;
	size_t		issort;
	size_t		lenght;
	size_t		visual;
}				t_stacks;

int				main(int ac, char **av);
char			*ft_strcpy(char *s1, char *s2);
int				ft_strcmp(char *s1, char *s2);
void			init_data(t_data **data);
void			pop(t_stack **st, t_data **list);
void			push(t_stack **st, int data, int index);
void			init_list(t_list **list);
void			clean_list(t_list **top);
void			free_str(char ***str);
void			clean_stacks(t_stacks	**stacks);
void			init_stacks(t_stacks **stacks, int size);
void			fail(char *str);
void			is_executeable(char *s);
void			execution(t_stacks **stacks);
void			execution2(t_stack **a, t_stack **b, char *s);
void			is_stacks(t_stacks **stacks);
void			swap2(t_stack *a, t_stack *b);
void			is_uni(t_list *a);
void			rotate2(t_stack *a, t_stack *b);
void			reverse_rotate2(t_stack *a, t_stack *b);
void			swap(t_stack *st);
void			stack_push(t_stack **a, t_stack **b);
void			rotate(t_stack **st);
t_data			*get_last_elem(t_list *list);
void			reverse_rotate(t_stack *st);
int				min(t_stack *st);
int				max(t_stack *st);
void			give_order_keys(t_list *list);
int				is_need_sorted(t_stack *st);
void			is_int(char **str);
void			quick_sort(t_stacks **stacks);
void			quick_sort2(t_stacks **stacks, size_t kol);
void			quick_sort3(t_stack *st, t_stacks **stacks);
void			exec_print(t_stacks **stacks, char *str);

#endif
