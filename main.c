/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:49:19 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/15 20:20:16 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Is_ordened
	.Chekea si un stack esta ordenado
	.Devuelve 1 si el stack esta ordenado, de lo contrario devuelve 0
*/

int	is_ordered(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Push_swap
	.Elige un método de ordenación dependiendo del número de valores a ordenar
*/

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_ordered(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_short(stack_a);
	else if (stack_size > 3 && !is_ordened(*stack_a))
		
}

/* Main
	.Comprueba si la entrada es correcta, en cuyo caso inicializara los stacks 
	a y b
	.Asigna indices a cada valor y ordena los stacks
	.Cuando termina de ordenar los stacks, libera los stacks y finaliza
*/

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!ft_input_correct(argv))
		error_exit(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_values_stack(argc, argv);
	stack_size = ft_size_stack (stack_a);
	ft_assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
