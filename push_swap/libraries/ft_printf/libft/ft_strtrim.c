/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <dde-alme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:04:13 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/24 12:06:24 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	len = ft_strlen(&s1[i]);
	if (len != 0)
	{
		while (s1[i + len -1]
			&& ft_strchr(set, s1[i + len - 1]) != NULL)
			len--;
	}
	return (ft_substr(s1, i, len));
}
/*
int	main(void)
{
	const char	*input = "	Hello, world!   ";
	const char	*set = " \t\n";

	char	*trimmed = ft_strtrim(input, set);
	if (trimmed != NULL)
	{
		printf("Originnal: \"%s\"\n", input);
		printf("Trimmed: \"%s\"\n", trimmed);
		free(trimmed);
	}
	else
	{
		printf("Trimmed string is NULL.\n");
	}
	return (0);
}*/
