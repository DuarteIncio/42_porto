/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:41:25 by dde-alme          #+#    #+#             */
/*   Updated: 2024/11/12 12:44:57 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long		min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MIN;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
