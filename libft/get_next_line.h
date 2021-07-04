/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:02:21 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/07 19:04:27 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_strlen(const char *s);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(const char *s1);
int				checker(char *save, char **line, int *flag, char **p);
int				get_next_line(int fd, char **line);
int				get_line(int fd, char **line, char **save);
int				ft_get_line2(int fd, char *buffer, char **line, char **save);
int				ft_get_line3(int *flag, char **save, char **p);

#endif
