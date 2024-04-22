/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:41:00 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/22 23:32:22 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Arg_is_number
	.Chekea si el argumento es un número (+1,1,-1 son todos números válidos)
	.Devuelve 1 si el argumento es un número, si no lo contrario(0)
*/

static	int	argument_is_number(char *argv)
{
	int	i;

	i = 0;

	if (argv[i] == '\0')
		return (0);
	if (ft_is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_is_digit(argv[i]))
		return (0);
	return (1);
}

/* Duplicates_numbers
	.Chekea si la lista de argumentos tiene números duplicados
	.Devuelve 1 si encuentra un número duplicado, de lo contrario 0
	
*/

static int	duplicate_numbers(t_stack **stack_a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack_a;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
			{
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

/* Ft_correct_output
	.Chekea si los argumentos dados son todos números, sin duplicados
	. Devuelve 1 si el argumento es válido, de lo contrario devuelve 0
*/

int	ft_correct_output(char **argv, t_stack **stack_a)
{
	int			i;
	long int	number;

	i = 1;

	while (argv[i])
	{
		if (!argument_is_number(argv[i]))
			return (0);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			error_exit(stack_a, NULL);
		if (i == 1)
			*stack_a = new_stack((int)number);
		else
			add_bottom_to_stack(stack_a, new_stack((int)number));
		i++;
	}
	if (duplicate_numbers(stack_a))
		return (0);
	return (1);
}
