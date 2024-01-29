/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:55:25 by dde-alme          #+#    #+#             */
/*   Updated: 2023/11/09 14:55:28 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(text, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(text);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		text = ft_strjoin(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*ft_get_line(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		str[i] = text[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean_first_line(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(text) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (text[i])
		str[j++] = text[i++];
	str[j] = '\0';
	free(text);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*array[1024];
	char		*output_text;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	array[fd] = ft_read_first_line(fd, array[fd]);
	if (!array[fd])
		return (NULL);
	output_text = ft_get_line(array[fd]);
	array[fd] = ft_clean_first_line(array[fd]);
	return (output_text);
}
