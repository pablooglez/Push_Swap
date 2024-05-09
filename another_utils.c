/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:00:31 by pablogon          #+#    #+#             */
/*   Updated: 2024/05/09 02:41:28 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Abs_number
	.Devuelve el valor absoluto de un número dado
	.El valor absoluto de un número se utiliza para calcular la distancia de
	este con respecto a 0, sea positivo o negativo
*/

int	abs_number(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/* Ft_putstr
	.Imprime los caracteres del string en una salida estandar
*/

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

/* Ft_atoi
	.Convierte una cadena de caracteres de un string en un entero largo
*/

long int	ft_atoi(const char *str)
{
	long int	number;
	int			isneg;
	int			i;

	number = 0;
	i = 0;
	isneg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * isneg);
}

/* Stack_free
	.Libera cada elemento de un stack dado y establece el puntero 
	del stack en NULL
*/

int	stack_free(t_stack **stack)
{
	t_stack	*tmp;

	while (stack && *stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
	return (0);
}

/* Error_exit
	.Escribir "Error\n" en la salida estándar despues de liberar los 
	stacks de a y b
	.Sale con el código de error de estándar 1
*/

void	error_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
		stack_free(stack_a);
	if (stack_b != NULL && *stack_b != NULL)
		stack_free(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
