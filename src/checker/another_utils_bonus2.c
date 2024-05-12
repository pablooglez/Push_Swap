/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_utils_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:21:45 by pablogon          #+#    #+#             */
/*   Updated: 2024/05/10 19:39:45 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(char *str1, char *str2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (*str1 && *str1 == *str2 && n > 1)
	{
		str1++;
		str2++;
		n--;
	}
	return ((char)*str1 - (char)*str2);
}

int	ft_is_space(char *str)
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

void	free_array(char **array, char *total)
{
	int	i;

	i = 0;
	while (array && array[i])
		free(array[i++]);
	free(array);
	free(total);
}
