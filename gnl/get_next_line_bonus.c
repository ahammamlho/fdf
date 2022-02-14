/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:18:27 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/13 12:41:29 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

void	ft_bzero(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		*(str + i) = 0;
		i++;
	}
}

char	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	while (i < (count * size))
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}

void	ft_init_rest(char **temp, char **result, char **rest, char **str_sub)
{
	*temp = 0;
	*result = 0;
	*str_sub = 0;
	if (*rest && *rest[0] != 0 && ft_strchr(*rest) == -1)
	{
			*result = ft_stradd_mot(*rest, *result, 0);
			*rest = 0;
	}
	else if (*rest && *rest[0] != 0)
	{
		*result = ft_substr(*rest, 0, ft_strchr(*rest) + 1, 0);
		*rest = ft_substr(*rest, ft_strchr(*rest) + 1, ft_strlen(*rest), 1);
	}
}

char	*get_next_line(int fd)
{
	char			*result;
	char			*temp;
	static char		*rest[4096];
	char			*str_sub;

	if (fd < 0)
		return (0);
	ft_init_rest(&temp, &result, &rest[fd], &str_sub);
	temp = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	while (ft_strchr(result) == -1 && read(fd, temp, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(temp) == -1)
			result = ft_stradd_mot(result, temp, 0);
		else
		{
			str_sub = ft_substr(temp, 0, ft_strchr(temp) + 1, 0);
			result = ft_stradd_mot(result, str_sub, 1);
			rest[fd] = ft_substr(temp, ft_strchr(temp) + 1, ft_strlen(temp), 0);
		}
		ft_bzero(temp);
	}
	ft_free_str(&temp);
	if ((rest[fd] && rest[fd][0] == 0) || (rest[fd] && !result))
		ft_free_str(&rest[fd]);
	return (result);
}

// int main()
// {
// 	int fd = open("files/multiple_nlx5", O_RDONLY);
// 	//int fd = open("get_next_line.c", O_RDONLY);
// 	if (fd == -1)
// 		printf("Error.\n");
// 	char *result;
// 	result = get_next_line(fd);
// 	int i = 0;
// 	while (result)
// 	{
// 		printf("%s", result);
// 		i++;
// 		result = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }