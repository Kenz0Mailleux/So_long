/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:24:01 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/18 15:30:11 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[sizetotal] = '\0';
	free(s1);
	return (res);
}

//renvoit l'indice de la premiere apparition de searchedChar
int	ft_strchr(char *s, int c, int d)
{
	int	len;

	len = 0;
	while (s[len] != 0)
	{
		if (s[len] == (char)c)
			return (len);
		len++;
	}
	if ((char)c == s[len])
		return (len);
	len = 0;
	while (s[len] != 0)
	{
		if (s[len] == (char)d)
			return (len);
		len++;
	}
	if ((char)d == s[len])
		return (len);
	return (-1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
