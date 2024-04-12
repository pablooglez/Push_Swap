/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:20:55 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/12 22:23:33 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Do_ra
	.Envia un elemento del stack_a a la ultima posición

*/
void	do_ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}