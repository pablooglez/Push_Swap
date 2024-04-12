/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:49:50 by pablogon          #+#    #+#             */
/*   Updated: 2024/04/11 20:37:56 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack_node
{
	int						value; //Número entero que debemos devolver//
	int						index; /*Indice en la lista de todo los valores 
									que deben ordenarse*/
	int						pos; //Posición actual en la fila//
	int						target_pos; /*Para elementos en el stack B, la 
										posición de destino en el stack A 
										donde debería estar*/
	int						cost_a; /*Cuántas acciones costaría rotar el 
									stack A para que el elemento en la posición 
									objetivo llegue a la parte superior del 
									stack A*/
	int						cost_b; /*Cuántas acciones costaría rotar el stack 
									B para que el elemento en la posición 
									objetivo llegue a la parte superior 
									del stack B*/
	struct s_stack			*next; //Puntero al siguiente elemento de la lista
}	t_stack;

/*Comprobación de Entrada (Input_Check_Utils)*/
int			ft_input_correct(char **argv);
int			ft_is_digit(char c);
int			ft_is_sign(char c);
int			ft_cmp_digitstr(const char *s1, const char *s2);

/*Another_Utils*/
int			abs_number(int nb);
void		ft_putstr(char *str);
int			ft_atoi(const char *str);
void		stack_free(t_stack **stack);
void		error_exit(t_stack **stack_a, t_stack **stack_b);





#endif