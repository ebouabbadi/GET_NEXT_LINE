/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:05:17 by ebouabba          #+#    #+#             */
/*   Updated: 2021/12/05 19:50:30 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(char *var_static, int fd)
{
	char	*var;
	int		r;

	var = malloc(BUFFER_SIZE + 1);
	if (var == NULL)
		return (NULL);
	r = 1;
	while (ft_backslash(var_static) == 0 && r != 0)
	{
		r = read(fd, var, BUFFER_SIZE);
		if (r == -1)
			return (free(var), NULL);
		if (r == 0)
			break ;
		var[r] = '\0';
		var_static = ft_strjoin(var_static, var);
	}
	free(var);
	return (var_static);
}

char	*ft_get_line(char *var_static)
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

char	*ft_flash_var(char *var_static)
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
	j = ft_strlen(var_static) - count;
	flash = ft_substr(var_static, count + 1, j);
	free(var_static);
	return (flash);
}

char	*get_next_line(int fd)
{
	char static	*var_static;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	var_static = ft_readfile(var_static, fd);
	if (!var_static)
		return (NULL);
	line = ft_get_line(var_static);
	var_static = ft_flash_var(var_static);
	return (line);
}
