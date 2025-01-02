/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:05:58 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/20 14:40:14 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

int				ft_atoi(const char *str);
void			ft_bzero(void *str, size_t size);
void			*ft_calloc(size_t nblocks, size_t size);
int				ft_isalnum(int x);
int				ft_isalpha(int x);
int				ft_isascii(int x);
int				ft_isdigit(int x);
int				ft_isprint(int x);
void			*ft_memchr(const void *str, int character, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t size);
void			*ft_memset(void *str, int x, size_t size);
char			*ft_strchr(const char *str, int character);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *dest, char *src, size_t size);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *str, int character);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_tolower(int x);
int				ft_toupper(int x);
void			ft_putnbr_fd(int x, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_itoa(int x);
char			**ft_split(const char *s, char c);
char			*ft_strtrim(const char *s1, const char *set);

#endif
