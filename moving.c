/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:07:26 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/17 19:10:08 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rev_rotate_both
	.Invierte la rotación de ambos stacks a y b hasta que uno de ellos este en
	posición
	.El coste dado es negativo ya que ambas posiciones están en la mitad inferior
	de sus respectivos stacks.
	.Se incrementara el coste a medida que rotan los stacks.Cuando se llega a 0, 
	el stack habrá rotado lo máximo posible y la posición superior será la 
	correcta
*/

static void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/* Rotate_both
	.Rota ambos stacks a y b hasta que uno de ellos este en posición
	.El coste dado es positivo ya que ambas posiciones están en la mitad 
	superior de sus respectivos stacks
	.Disminuira el coste a medida que rotan los stacks. Cuando se llega a 0, 
	el stack habrá rotado lo máximo posible y la posicióm superior será 
	la correcta.
*/

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/* Rotate_a
	.Rota el stack a hasta que este en su posición.
	.Si el coste es negativo, el stack será rotate reverse, si es positivo será
	rotate
*/

static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/* Rotate_b
	.Rota el stack b hasta que este en su posición
	.Si el coste es negativo, el stack será rotate reverse, si es positivo será
	rotate
*/

static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}
/* Moving
	.Elige que movimiento hacer para llevar el elemento del stack b a la
	posición correcta del stack a
	.Si los costes de mover los stacks a y b coinciden, ambas se rotarán e 
	invertirán al mismo timepo.
	.También podría rotarse por separado, antes de empujar finalmente el elemento
	superior del stack b a la zona superior del stack a
*/

void	moving(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	do_pa(a, b);
}
