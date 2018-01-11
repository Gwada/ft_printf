/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:19:17 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/11 19:49:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!c || c == s[i])
		return ((char*)(s + i));
	return (NULL);
}

int		ft_strchri(const char *s, unsigned c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (*s && *s != (char)c)
	{
		s++;
		i++;
	}
	return (*s == (char)c ? i : -1);
}

int		ft_strchri_up(const char *s, unsigned c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (*s && *s != (char)c && *s != (char)c + 32)
	{
		s++;
		i++;
	}
	return ((*s == (char)c || *s == (char)c + 32) ? i : -1);
}
