/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:01:03 by pablogon          #+#    #+#             */
/*   Updated: 2024/05/10 20:01:39 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlcpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (*(src + i))
		i++;
	if (!n)
		return (i);
	while (--n && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (i);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static int	ft_strlcat(char *dest, char *src, int n)
{
	int		dest_len;
	int		total_len;
	char	*s;

	if ((!dest || !src) && !n)
		return (0);
	s = src;
	dest_len = 0;
	while (*(dest + dest_len) && dest_len < n)
		dest_len++;
	if (dest_len < n)
		total_len = dest_len + ft_strlen(s);
	else
		return (n + ft_strlen(s));
	while (*s && (dest_len + 1) < n)
	{
		*(dest + dest_len) = *s++;
		dest_len++;
	}
	*(dest + dest_len) = '\0';
	return (total_len);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		m_len;

	if (start > ft_strlen(s))
		m_len = 0;
	else
		m_len = ft_strlen(s) - start;
	if (len > m_len)
		len = m_len;
	len += 1;
	str = (char *)malloc(len);
	if (str == NULL)
		return (NULL);
	if (len > 1)
		ft_strlcpy(str, s + start, len);
	else
		str[0] = '\0';
	return (str);
}

char	*ft_strjoin_c(char *str1, char *str2, char *sp, int md)
{
	char	*ret;
	int		len;

	if (!str1)
	{
		if (md == 2 || md == 3)
			free(str2);
		return (NULL);
	}
	len = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(sp);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret)
		ft_strlcpy(ret, str1, len + 1);
	if (ret && str2 && sp)
	{
		ft_strlcat(ret, sp, len + 1);
		ft_strlcat(ret, str2, len + 1);
	}
	if (md == 1 || md == 3)
		free(str1);
	if (md == 2 || md == 3)
		free(str2);
	return (ret);
}
