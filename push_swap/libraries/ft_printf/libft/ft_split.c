/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <dde-alme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:12:18 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/24 12:06:13 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_cpy(const char *str, int start, int finish)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = word_cpy(s, index, i);
			j++;
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*
int main() 
{
    char input[] = "Hello world everything good";
    char delimiter = ' ';
    char **result = ft_split(input, delimiter);

    if (result) 
    {
        for (int i = 0; result[i] != NULL; i++) 
	{
            printf("Word %d: %s\n", i, result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("Split function.\n");
    }
    return 0;
}*/
