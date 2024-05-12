/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:30:57 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/23 20:38:14 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Is_sign:
	.Comprueba si el carácter es de signo número sea + o -
	.Devolver 1 si el carácter es un digito, en caso contrario 0 */

int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* Is_digit:
	.Comprueba si el carácter es un digito
	.Devolver 1 si el carácter es un digito, en caso contrario 0 */

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* Cmp_digistr
	.Compara dos strings de dígitos para comprobar si son iguales o no
	.Si uno de los strings comienza con signo '+', se ignora y comprueba el resto
	de números de la cadena (+123 == 123 pero -123 != 123)
	.Devuelve 0 si los strings coinciden, otro valor si no
*/

int	ft_cmp_digitstr(const char *str1, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (str1[i] == '+')
		i++;
	if (str2[j] == '+')
		j++;
	if (str1[i] == '-' && str2[j] == '-')
	{
		i++;
		j++;
	}
	while (str1[i] == '0')
		i++;
	while (str2[j] == '0')
		j++;
	while (str1[i] != '\0' && str2[j] != '\0' && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[j]);
}
