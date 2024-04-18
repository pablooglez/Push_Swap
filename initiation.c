/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:23:25 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/17 18:51:36 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fill_values_stack
	.LLena el stack_a con los valores proporcionados
	.Si los valores están fuera del rango de enteros,
	imprime error y sale del programa
*/

t_stack	*fill_values_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	number;
	int			i;

	stack_a = NULL;
	number = 0;
	i = 1;
	while (i < argc)
	{
		number = ft_atoi (argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			error_exit(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack((int)number);
		else
			add_bottom_to_stack(&stack_a, new_stack((int)number));
		i++;
	}
	return (stack_a);
}

/* Ft_assign_index
	.Asigna un índice a cada valor en el stack a. Es una forma comoda
	de ordenar el stack porque se pueden chekear y comprobar índices
	en lugar de valores reales
	
	Values:		-5		7		0		2
	Index:		[1]		[2]		[3]		[4]

	.Los índices siempre iran asignados de mayor (tamaño del stack) al
	menor (1)
*/

void	ft_assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
