/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:54:36 by ebouabba          #+#    #+#             */
/*   Updated: 2021/12/05 19:59:13 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfile_bs(char *var_static, int fd)
{
	char	*var;
	int		r;

	var = malloc(BUFFER_SIZE + 1);
	if (var == NULL)
		return (NULL);
	r = 1;
	while (ft_backslash_bs(var_static) == 0 && r != 0)
	{
		r = read(fd, var, BUFFER_SIZE);
		if (r == -1)
			return (free(var), NULL);
		if (r == 0)
			break ;
		var[r] = '\0';
		var_static = ft_strjoin_bs(var_static, var);
	}
	free(var);
	return (var_static);
}

char	*ft_get_line_bs(char *var_static)
{
	int		count;
	char	*nev_var;

	count = 0;
	if (var_static[0] == '\0')
		return (NULL);
	while (var_static[count] != '\n' && var_static[count])
		count++;
	nev_var = malloc(count + 2);
	if (nev_var == NULL)
		return (NULL);
	count = -1;
	while (var_static[++count] && var_static[count] != '\n')
		nev_var[count] = var_static[count];
	if (var_static[count] == '\n')
		nev_var[count++] = '\n';
	nev_var[count] = '\0';
	return (nev_var);
}

char	*ft_flash_var_bs(char *var_static)
{
	char	*flash;
	int		count;
	int		j;

	count = 0;
	while (var_static[count] != '\n' && var_static[count])
		count++;
	if (var_static[count] == '\0')
	{
		free(var_static);
		return (NULL);
	}
	j = ft_strlen_bs(var_static) - count;
	flash = ft_substr_bs(var_static, count + 1, j);
	free(var_static);
	return (flash);
}

char	*get_next_line(int fd)
{
	char static	*var_static[6500];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	var_static[fd] = ft_readfile_bs(var_static[fd], fd);
	if (!var_static[fd])
		return (NULL);
	line = ft_get_line_bs(var_static[fd]);
	var_static[fd] = ft_flash_var_bs(var_static[fd]);
	return (line);
}
