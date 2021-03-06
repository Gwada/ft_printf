/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:06:22 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/12 10:07:20 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t					ft_strlen(const char *s)
{
	size_t				i;

	i = 0;
	if (s)
		while (s[i])
			++i;
	return (i);
}

void					ft_bzero(void *s, size_t n)
{
	while (n)
		*((char*)s + n-- - 1) = '\0';
}

int						ft_atoi_p(const char *nptr)
{
	int					num;
	int					pos_num;
	unsigned long long	max;

	max = 0;
	num = 0;
	pos_num = 1;
	if (*nptr == '-' || *nptr == '+')
		*nptr++ == '-' ? pos_num = -1 : 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		max = max * 10 + *nptr++ - '0';
		if (max > 9223372036854775807)
			return ((pos_num == 1) ? -1 : 0);
		num = (int)max;
	}
	return (num * pos_num);
}

size_t					ft_wcharlen(wchar_t c)
{
	if (c >= 0)
	{
		if ((c < 0x80 && MB_CUR_MAX > 0) || (c < 0x100 && MB_CUR_MAX == 1))
			return (1);
		else if (c > 0x7f && c < 0x800 && MB_CUR_MAX > 1)
			return (2);
		else if (MB_CUR_MAX > 2
		&& ((c >= 0x800 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFF)))
			return (3);
		else if (c > 0x10000 && c <= 0x10FFFF && MB_CUR_MAX > 3)
			return (4);
	}
	return (0);
}

size_t					ft_wstrlen(wchar_t *ws)
{
	size_t				wstrlen;

	wstrlen = 0;
	while (*ws != L'\0')
		wstrlen += ft_wcharlen(*ws++);
	return (wstrlen);
}
