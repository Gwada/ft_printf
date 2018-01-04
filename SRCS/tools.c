/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:08:44 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/09 20:20:38 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	   while (s[i])
		   ++i;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	while (n)
		*((char*)s + n-- - 1) = '\0';
}

int		ft_atoi_p(const char *nptr)
{
	int					i;
	int					num;
	int					pos_num;
	unsigned long long	max;

	i = 0;
	max = 0;
	num = 0;
	pos_num = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			pos_num = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		max = max * 10 + nptr[i] - '0';
		if (max > 9223372036854775807)
			return ((pos_num == 1) ? -1 : 0);
		num = num * 10 + nptr[i++] - '0';
	}
	return (num * pos_num);
}
