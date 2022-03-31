/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:21:27 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/12 21:22:55 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h> // open fct
# include <stdio.h>
# include <unistd.h> // read fct
# include <stdlib.h> // malloc

int		ft_strlen_gnl(char *str);
void	ft_free_str(char **p);
int		ft_strchr_gnl(char *str);
char	*get_next_line(int fd);
char	*ft_stradd_mot(char *src, char *mot, int a);
void	ft_bzero_gnl(char *str);
char	*ft_calloc_gnl(int count, int size);
void	ft_init_rest(char **temp, char **result, char **rest, char **str_sub);
char	*ft_substr_gnl(char *s, int start, int len, int free_or_not);

#endif