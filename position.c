/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:29:54 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/16 17:42:23 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Get_position
	.Asigna una posición a cada elemento de un stack de arriba a abajo en orden
	ascendente
	
	.Values:	3		0		9		1
	.Index:		[3]		[1]		[4]		[2]
	.Posición	<0>		<1>		<2>		<3>
	.Se utiliza para calcular el coste de mover un determinado número a una 
	determinada posición
*/

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
/* Get_lowest_index_position
	.Obtiene la posición actual de un elemento con el index más bajo dentro 
	de un stack
*/

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_post;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_post = tmp->next;
	while (tmp)
	{
		if (tmp-> index < lowest_index)
		{
			lowest_index = tmp-> index;
			lowest_post = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_post);
}

/* Get_target
	.Elige la mejor posición target en el stack a para el indice dado en
	un elemento del stack B
	.Chekea si el índice del elemento b puede colocarse en algún lugar entre 
	los elementos del stack a, chekeando si hay un elemento en el stack a con un
	index mayor.
	.Si no es así, buscará el elemento con el index más pequeño en a y lo 
	asignará como posición target
*/

static int	get_target(t_stack **a, int b_idx, int target_indx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_indx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* Get_target_position
	.Asigna una posición target en el stack a a cada elemento del stack a
	.La posición targeet es el punto al que debe llegar el elemento B para
	ser ordenado correctamente.
	.Esta posición se usara para calcular el coste de mover cada elemento a su
	posición target en el stack a
*/

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

