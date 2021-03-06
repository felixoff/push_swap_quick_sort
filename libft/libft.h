/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjennett <sjennett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:56:55 by sjennett          #+#    #+#             */
/*   Updated: 2021/03/08 19:15:02 by sjennett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(const char *s, int fd);
char			*ft_itoa(int n);
char			*ft_strchr(char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
const char *needle, size_t len);
char			*ft_strdup(const char *s1);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t count, size_t size);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memchr(void *s, int c, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_memcmp(void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
long			ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(const char *s1);
int				checker(char *save, char **line, int *flag, char **p);
int				get_next_line(int fd, char **line);
int				get_line(int fd, char **line, char **save);
int				ft_get_line2(int fd, char *buffer, char **line, char **save);
int				ft_get_line3(int *flag, char **save, char **p);

#endif
