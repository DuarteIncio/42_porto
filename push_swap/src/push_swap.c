/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:38:55 by dde-alme          #+#    #+#             */
/*   Updated: 2024/11/12 11:46:33 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 1 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	init_stack_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false)
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
