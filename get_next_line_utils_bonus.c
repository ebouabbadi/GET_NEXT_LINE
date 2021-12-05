/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:52:02 by ebouabba          #+#    #+#             */
/*   Updated: 2021/12/05 19:53:23 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_bs(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_backslash_bs(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i++])
			if (s[i] == '\n')
				return (1);
	return (0);
}

char	*ft_strjoin_bs(char *var_static, char *var)
{
	size_t	i;
	size_t	j;
	char	*nv_var;

	if (!var_static)
		var_static = ft_strdup_bs("");
	if (!var_static || !var)
		return (NULL);
	nv_var = malloc(sizeof(char)
			* (ft_strlen_bs(var) + ft_strlen_bs(var_static) + 1));
	if (!nv_var)
		return (NULL);
	i = -1;
	if (var_static)
		while (var_static[++i] != '\0')
			nv_var[i] = var_static[i];
	j = 0;
	while (var[j] != '\0')
		nv_var[i++] = var[j++];
	nv_var[i] = '\0';
	free(var_static);
	return (nv_var);
}

char	*ft_strdup_bs(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;

	len = ft_strlen_bs((char *)s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr_bs(char *var_static, int start, int len)
{
	char	*nev_var;
	int		i;

	i = -1;
	if (start >= ft_strlen_bs(var_static))
	{
		nev_var = malloc(sizeof(char));
		nev_var[0] = 0;
		return (nev_var);
	}
	if (len > (ft_strlen_bs(var_static) - start))
		nev_var = malloc(ft_strlen_bs(var_static) - start + 1);
	else
		nev_var = malloc(len + 1);
	if (!nev_var)
		return (NULL);
	while (var_static[start + ++i] && i < len)
		nev_var[i] = var_static[start + i];
	nev_var[i] = 0;
	return (nev_var);
}
