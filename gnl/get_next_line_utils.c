/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:46:59 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/12 21:18:03 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	ft_free_str(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = 0;
	}
}

int	ft_strchr_gnl(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_stradd_mot(char *src, char *mot, int a)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = 0;
	result = (char *)ft_calloc_gnl(ft_strlen_gnl(src) + ft_strlen_gnl(mot) + 1, 1);
	if (!result)
		return (0);
	while (src && src[i])
		result[j++] = src[i++];
	i = 0;
	while (mot && mot[i])
		result[j++] = mot[i++];
	result[j] = '\0';
	if (src)
		ft_free_str(&src);
	if (a)
		ft_free_str(&mot);
	return (result);
}

char	*ft_substr_gnl(char *s, int start, int len, int free_or_not)
{
	char	*result;
	int		i;

	i = 0;
	if (!s)
		return ((char *)ft_calloc_gnl(1, 1));
	if (ft_strlen_gnl(s) < start || len == 0)
	{
		return ((char *)ft_calloc_gnl(1, 1));
	}
	if (ft_strlen_gnl(s) - start < len)
		result = (char *)ft_calloc_gnl(ft_strlen_gnl(s) - start + 1, 1);
	else
		result = (char *)ft_calloc_gnl(len + 1, 1);
	if (!result)
		return (0);
	while (s[i + start] != '\0' && i < len)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	if (free_or_not)
		ft_free_str(&s);
	return (result);
}
