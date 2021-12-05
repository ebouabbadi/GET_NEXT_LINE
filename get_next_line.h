/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:05:52 by ebouabba          #+#    #+#             */
/*   Updated: 2021/12/05 19:05:29 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *var_static, char *var);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
char	*ft_get_line(char *var_static);
char	*ft_readfile(char *var_static, int fd);
int		ft_backslash(char *s);
char	*ft_strdup(const char *s1);

#endif
