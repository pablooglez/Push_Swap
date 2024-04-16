/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:20:55 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/15 18:42:37 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Do_ra
	.Envia un elemento del stack_a a la ultima posición

*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* Do_rb
	.Envia un elemento del stack_b a la ultima posición
	.Imprime "rb" en la salida estandar
*/

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/*do_rr
	.Envia el elemento superior del stack_a y del stack_b al fondo de sus
	respectivos stacks
	.Imprime "rr" en la salida estándar
*/

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("rr\n");
}

/* Static void rotate
	.El elemento superior de un stack se envia a la última posición
*/

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*queue;

	tmp = *stack;
	*stack = (*stack)->next;
	queue = get_stack_bottom(*stack);
	tmp->next = NULL;
	queue->next = tmp;
}
