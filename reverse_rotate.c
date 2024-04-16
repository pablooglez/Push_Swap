/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:08:21 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/15 20:18:29 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Do_rra
	. Envia el último elemento del stack_a a la primera posición
	.Imprime "rra" en la salida estándar
*/

void	do_rra(t_stack **stack_a)
{
	rev_rotate(*stack_a);
	ft_putstr("rra\n");
}

/* Do_rrb
	. Envia el último elemento del stack_b a la primera posición
	. Imprime "rrb" en la salida estándar
*/

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(*stack_b);
	ft_putstr("rrb\n");
}

/* Do_rrr
	.Envia el último elemento del stack_a y del stack_b al principio de sus
	respectivos stacks
	.Imprime "rrr" en la salida estándar"
*/

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(*stack_a);
	rev_rotate(*stack_b);
	ft_putstr("rrr\n");
}

/* Rev_rotate
	.Envia el último elemento de un stack a la primera posición
*/

static int	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*queue;
	t_stack	*before_queue;

	queue = get_stack_bottom(*stack);
	before_queue = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = queue;
	(*stack)->next = tmp;
	before_queue->next = NULL;
}
