/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:10:46 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/12 22:20:41 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Search_highest_index
	.Devuelve el índice más alto de un stack
*/

static int	search_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort
	.Ordena un stack de 3 números en 2 o menos movimientos. La ordenación se 
	realiza por índices y no por valores absolutos
	


*/

void	tiny_sort(t_stack **stack)
{
	int	highest;
	
	if (!is_ordened(*stack))
		return ;
	highest = search_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra
}