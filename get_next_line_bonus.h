/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:07:01 by ebouabba          #+#    #+#             */
/*   Updated: 2021/12/05 21:53:00 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strjoin_bs(char *var_static, char *var);
char	*ft_substr_bs(char *s, int start, int len);
int		ft_strlen_bs(char *s);
char	*ft_get_line_bs(char *var_static);
char	*ft_readfile_bs(char *var_static, int fd);
int		ft_backslash_bs(char *s);
char	*ft_strdup_bs(const char *s1);

#endif
