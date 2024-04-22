/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:07:39 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/23 00:40:50 by pablogon         ###   ########.fr       */
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

	stack_size = ft_size_stack(*stack_a);
	pushed = 0;
	while (stack_size > 6 && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
	}
	
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/*	Shift_stack
	. Después de ordenar la mayor parte de un stack, desplaza el stack a hasta
	que el menor valor este arriba del todo.
	. Si se encuentra en la mitad inferior del stack, se gira en sentido 
	contrario a su posición. De lo contrario, lo gira hasta que se encuentre en 
	la parte superior del stack.
*/

static void	shift_stack(t_stack **stack_a)
{
	int	lowest_position;
	int	stack_size;

	stack_size = ft_size_stack(*stack_a);
	lowest_position = get_lowest_index_position(stack_a);
	if (lowest_position > stack_size / 2)
	{
		while (lowest_position < stack_size)
		{
			do_rra(stack_a);
			lowest_position++;
		}
	}
	else
	{
		while (lowest_position > 0)
		{
			do_ra(stack_a);
			lowest_position--;
		}
	}
}

/* Sort
	.Algoritmo de ordenación para un stack mayor de 3
	.Pushea todo menos 3 números al stack b
	.Ordena los 3 números que quedan en el stack a
	.Calcula el movimiento más costo-eficiente
	.Desplazará elementos hasta que el stack a este ordenado
*/

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		most_cheaper_move(stack_a, stack_b);
	}
	if (!is_ordered(*stack_a))
		shift_stack(stack_a);
}
