/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:28:51 by dde-alme          #+#    #+#             */
/*   Updated: 2024/11/12 11:38:37 by dde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libraries/libft.h"
# include "../libraries/ft_printf.h"

typedef struct	s_stack_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool		above_median;
	bool		cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}		t_stack_node;





#endif
