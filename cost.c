/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:07:15 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/17 18:35:44 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Cost
	.Calcula el coste de movimientos de cada elemento del stack b para su 
	correcta posición en el stack a
	. Para ello se calcula dos costes:
		.Cost_b representa el coste de llevar el elemento a la parte superior 
		del stack b
		.Cost_a representa el coste de llevar el elemento a la parte superior 
		del stack a
	.Si el elemento esta en la mitad inferior del stack, el coste será negativo.
	En caso contrario, el coste será positivo
*/

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_size_stack(tmp_a);
	size_b = ft_size_stack(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/* Most_cheaper_move
	.Encuentra el elemento del stack b con el coste más barato para moverlo al
	stack a y lo mueve a la posición correcta del stack a
*/

void	most_cheaper_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;
	int		ch;

	tmp = *stack_b;
	ch = INT_MAX;
	while (tmp)
	{
		if (abs_number(tmp->cost_a) + abs_number(tmp->cost_b) < abs_number(ch))
		{
			ch = abs_number(tmp->cost_b) + abs_number(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	moving(stack_a, stack_b, cost_a, cost_b);
}
