/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:39:46 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/17 20:58:32 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap
	.Intercambia los dos primeros elementos de un Stack
	.No hará nada si hay solo uno o ningún elemento
*/

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* Do_sa
	.Intercambia los dos primeros elementos del stack_a
	.Imprime "sa" en la salida estándar
*/

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* Do_sb
	.Intercambia los dos primeros elementos del stack_b
	.Imprime "sb" en la salida estándar
*/

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* Do_ss
	.Intercambia los dos primeros elementos del stack_a y los dos primeros
	elementos del stack_b
	.Imprime "ss" en la salida estándar
*/

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
