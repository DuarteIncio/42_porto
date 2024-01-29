/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:30:47 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/11 11:59:35 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int character)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)character)
			ptr = (char *)(s + i);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)character)
		ptr = (char *)(s + i);
	return (ptr);
}
/*
int main(void)
{
    char str[] = "Hello, world!";
    int targetchar = 'o';

    char *result = ft_strrchr(str, targetchar);

    if (result != NULL)
    {
        printf("Found %c at position: %ld\n", targetchar, result - str);
    }
    else
    {
        printf("%c not found in the string.\n", targetchar);
    }
}*/
