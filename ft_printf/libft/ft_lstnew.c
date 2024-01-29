/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <dde-alme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:49:25 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/30 12:38:14 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
/*
int	main(void)
{
	char	data[] = "Hello, world!";
	t_list	*newList = ft_lstnew(&data);

	if (newList)
		printf("New list content: %s\n", (char *)(newList->content));
	else
		printf("Failed to create a new list.\n");
	free(newList);
	return (0);
}*/
