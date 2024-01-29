/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:22:12 by dde-alme          #+#    #+#             */
/*   Updated: 2023/11/09 14:30:12 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *str);
char	*ft_strchr(char *str, int character);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_first_line(int fd, char *text);
char	*ft_get_line(char *text);
char	*ft_clean_first_line(char *text);
char	*get_next_line(int fd);

#endif
