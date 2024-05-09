/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:49:19 by pablogon          #+#    #+#             */
/*   Updated: 2024/05/09 02:45:10 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Is_ordened
	.Chekea si un stack esta ordenado
	.Devuelve 1 si el stack esta ordenado, de lo contrario devuelve 0
*/

int	is_ordered(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Push_swap
	.Elige un método de ordenación dependiendo del número de valores a ordenar
*/

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_ordered(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_ordered(*stack_a))
		sort(stack_a, stack_b);
}

static void	free_array(char **array, char *total)
{
	int	i;

	i = 0;
	while (array && array[i])
		free(array[i++]);
	free(array);
	free(total);
}

static int	ft_is_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if ((str[i] < 9 || str[i] > 13) && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

/* Main
	.Comprueba si la entrada es correcta, en cuyo caso inicializara los stacks 
	a y b
	.Asigna indices a cada valor y ordena los stacks
	.Cuando termina de ordenar los stacks, libera los stacks y finaliza
*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	*total;
	char	**total2;

	stack_size = 1;
	if (argc < 2)
		return (0);
	total = ft_strjoin_c("", NULL, "", 0);
	while (stack_size < argc)
		total = ft_strjoin_c(total, argv[stack_size++], " ", 1);
	if (!total || ft_is_space(total))
		error_exit(NULL, NULL);
	total = ft_strjoin_c("PS", total, " ", 2);
	total2 = ft_split(total, ' ');
	if (!ft_correct_output(total2, &stack_a))
		error_exit(NULL, NULL);
	free_array(total2, total);
	stack_b = NULL;
	stack_size = ft_size_stack (stack_a);
	ft_assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	argc = stack_free(&stack_a) + stack_free(&stack_b);
	exit (0);
}
