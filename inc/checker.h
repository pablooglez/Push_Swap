/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:24:55 by pablogon          #+#    #+#             */
/*   Updated: 2024/05/14 17:16:20 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int						value;
	int						index;
	int						pos;
	int						target_pos;
	int						cost_a;
	int						cost_b;
	struct s_stack			*next;
}	t_stack;

/* (Input_Check_Utils) */
int			ft_is_digit(char c);
int			ft_is_sign(char c);
int			ft_cmp_digitstr(const char *s1, const char *s2);
int			ft_correct_output(char **argv, t_stack **stack_a);
int			is_valid_cmd(char *command);

/*Another_Utils */
int			abs_number(int nb);
void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
int			stack_free(t_stack **stack);
void		error_exit(t_stack **stack_a, t_stack **stack_b);

/* (Stack) */
t_stack		*new_stack(int value);
void		add_bottom_to_stack(t_stack **stack, t_stack *new);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
int			ft_size_stack(t_stack *stack);

/* Sorting algorithms */
int			is_ordered(t_stack *stack);

/* Operators */
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

/*Split*/
char		*ft_substr(char *s, int start, int len);
char		**ft_split(char *s, char c);

/* Ft_strjoin_c */
char		*ft_strjoin_c(char *str1, char *str2, char *sp, int md);

/* Another_Utils_bonus */
int			ft_strncmp(char *str1, char *str2, unsigned int n);
int			ft_is_space(char *str);
void		free_array(char **array, char *total);
void		execute_commands(t_stack *stack_a, t_stack *stack_b);
void		execute_command(char *command, t_stack **stack_a, \
	t_stack **stack_b);
char		**reading_bytes(void);

#endif