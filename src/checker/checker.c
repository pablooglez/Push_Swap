/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:24:11 by pablogon          #+#    #+#             */
/*   Updated: 2024/05/13 21:10:03 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include <string.h>

int	is_ordered(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

char	**reading_bytes(void)
{
	char	*line;
	char	buffer[2];
	int		readed;
	int		is_error;

	is_error = 0;
	line = ft_strjoin_c("", NULL, "", 0);
	readed = read(0, &buffer, 1);
	buffer[readed] = '\0';
	while (readed > 0)
	{
		if ((buffer[0] >= 9 && buffer[0] <= 13 && buffer[0] != 10)
			|| buffer[0] == 32)
			is_error = 1;
		line = ft_strjoin_c(line, buffer, "", 1);
		readed = read(0, &buffer, 1);
		if (readed < 0)
			return (free(line), NULL);
		buffer[readed] = '\0';
	}
	if (!line)
		return (NULL);
	if (is_error)
		error_exit(NULL, NULL);
	return (ft_split(line, '\n'));
}

void	execute_command(char *command, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(command, "pb", 2))
		do_pb(stack_a, stack_b);
	else if (!ft_strncmp(command, "pa", 2))
		do_pa(stack_a, stack_b);
	else if (!ft_strncmp(command, "ra", 2))
		do_ra(stack_a);
	else if (!ft_strncmp(command, "rb", 2))
		do_rb(stack_b);
	else if (!ft_strncmp(command, "rra", 3))
		do_rra(stack_a);
	else if (!ft_strncmp(command, "rrb", 3))
		do_rrb(stack_b);
	else if (!ft_strncmp(command, "rrr", 3))
		do_rrr(stack_a, stack_b);
	else if (!ft_strncmp(command, "rr", 2))
		do_rr(stack_a, stack_b);
	else if (!ft_strncmp(command, "sa", 2))
		do_sa(stack_a);
	else if (!ft_strncmp(command, "sb", 2))
		do_sb(stack_b);
	else if (!ft_strncmp(command, "ss", 2))
		do_ss(stack_a, stack_b);
	else if (command && *command)
		error_exit(stack_a, stack_b);
	free(command);
}

void	execute_commands(t_stack *stack_a, t_stack *stack_b)
{
	char	**commands;
	int		i;

	i = 0;
	commands = reading_bytes();
	while (commands && commands[i])
	{
		if (!is_valid_cmd(commands[i++]))
			error_exit(NULL, NULL);
	}
	i = 0;
	while (commands && commands[i])
		execute_command(commands[i++], &stack_a, &stack_b);
	free(commands);
	if (!is_ordered(stack_a) || stack_b)
		write(2, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

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
	execute_commands(stack_a, stack_b);
	argc = stack_free(&stack_a) + stack_free(&stack_b);
	exit (0);
}
