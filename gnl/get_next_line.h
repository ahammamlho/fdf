/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:46:56 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/12 21:20:11 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> // open fct
# include <stdio.h>
# include <unistd.h> // read fct
# include <stdlib.h> // malloc

int		ft_strlen(char *str);
void	ft_free_str(char **p);
int		ft_strchr(char *str);
char	*get_next_line(int fd);
char	*ft_stradd_mot(char *src, char *mot, int a);
void	ft_bzero(char *str);
char	*ft_calloc(int count, int size);
void	ft_init_rest(char **temp, char **result, char **rest, char **str_sub);
char	*ft_substr(char *s, int start, int len, int free_or_not);

#endif