/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:46:21 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/17 18:43:58 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Get_stack_bottom
	.Devuelve el último elemento de un stack
*/

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*Get_stack_before_bottom
	.Devuelve el penúltimo elemento de un stack
*/

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/* New_stack
	.Crea un stack de elementos con el valor proporcionado
	.Devuelve el nuevo elemento del stack creado
*/

t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/*Add_bottom_to_stack
	.Añade un elemento al final de un stack
*/

void	add_bottom_to_stack(t_stack **stack, t_stack *new)
{
	t_stack	*queue;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	queue = get_stack_bottom(*stack);
	queue->next = new;
}

/* Size_stack
	.Devuelve el número de elementos de un stack
*/

int	ft_size_stack(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
