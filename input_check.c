/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:41:00 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/17 21:05:28 by pablogon         ###   ########.fr       */
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

static int	duplicate_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && ft_cmp_digitstr(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Argument_is_zero
	.Chekea si el argumento es 0 para evitar duplicados de +0,0,-0
	.Devuelve 1 si el argumento es cero, devuelve 0 si contiene cualquier 
	otra cosa distinta de cero 
*/

static int	argument_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (ft_is_digit(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/* Ft_correct_output
	.Chekea si los argumentos dados son todos números, sin duplicados
	. Devuelve 1 si el argumento es válido, de lo contrario devuelve 0
*/

int	ft_correct_output(char **argv)
{
	int	i;
	int	numbers_zeros;

	i = 1;
	numbers_zeros = 0;
	while (argv[i])
	{
		if (!argument_is_number(argv[i]))
			return (0);
		numbers_zeros += argument_is_zero(argv[i]);
		i++;
	}
	if (numbers_zeros > 1)
		return (0);
	if (duplicate_numbers(argv))
		return (0);
	return (1);
}
