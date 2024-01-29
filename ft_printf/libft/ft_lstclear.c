/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <dde-alme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:48:14 by dde-alme          #+#    #+#             */
/*   Updated: 2023/10/20 11:54:57 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*tmp;

	i = *lst;
	while (i)
	{
		tmp = i->next;
		ft_lstdelone(i, del);
		i = tmp;
	}
	*lst = NULL;
}
