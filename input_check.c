/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:41:00 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/11 20:50:27 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Arg_is_number
	.Chekea si el argumento es un número (+1,1,-1 son todos números válidos)
	.Devuelve 1 si el argumento es un número, si no lo contrario(0)


*/
static	int	arg_is_number(char *argv)
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