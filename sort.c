/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:07:39 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/15 20:53:37 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push_all_save_three
	.Pushea todo los elementos del stack_a al stack_b, excepto los tres últimos
	.Pushea primero los valores más pequeños y luego los más grandes para ayudar
	a la eficiencia de la ordenación
*/

static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_size_stack(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb()
		}
	}
}


void	sort(t_stack **stack_a, t_stack **stack_b)
{
	
}