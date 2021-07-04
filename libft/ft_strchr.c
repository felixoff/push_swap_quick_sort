/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:15:43 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/07 19:01:54 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char			*a;
	unsigned char	b;
	int				i;

	a = (char *)s;
	b = (unsigned char)c;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == b)
			return (&a[i]);
		i++;
	}
	if (a[i] == b)
		return (&a[i]);
	return (NULL);
}
