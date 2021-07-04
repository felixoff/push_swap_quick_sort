/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:45:03 by sjennett          #+#    #+#             */
/*   Updated: 2020/11/09 17:38:57 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*a;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(a = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		a[i] = s2[j];
		i++;
		j++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strdup(const char *s1)
{
	long int	i;
	char		*a;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0')
	{
		i++;
	}
	if (!(a = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			*s = '\0';
			return ((char*)s);
		}
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (0);
}
