/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:18:40 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/12 21:22:36 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
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

int	ft_strchr(char *str)
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
	result = (char *)ft_calloc(ft_strlen(src) + ft_strlen(mot) + 1, 1);
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

char	*ft_substr(char *s, int start, int len, int free_or_not)
{
	char	*result;
	int		i;

	i = 0;
	if (!s)
		return ((char *)ft_calloc(1, 1));
	if (ft_strlen(s) < start || len == 0)
	{
		return ((char *)ft_calloc(1, 1));
	}
	if (ft_strlen(s) - start < len)
		result = (char *)ft_calloc(ft_strlen(s) - start + 1, 1);
	else
		result = (char *)ft_calloc(len + 1, 1);
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
