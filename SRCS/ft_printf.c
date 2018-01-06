/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:00 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/06 14:27:42 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_printf(t_data *data, const char *s, int fd)
{
	ft_bzero(data, sizeof(*data));
	data->ft = (char*)s;
	data->fd = fd;
}

int			ft_printf(const char *format, ...)
{
	t_data	data;

	ft_init_printf(&data, format, 1);
	va_start(data.ap, format);
	while (*data.ft && !data.error)
	{
		if (*data.ft == '%')
			ft_attribuate(&data);
		else if (*data.ft++ && ++data.i == BUFF_SIZE)
		{
			ft_buffering(&data, data.ft - data.i, BUFF_SIZE);
			data.i = 0;
		}
	}
	!data.error ? ft_buffering(&data, data.ft - data.i, data.i) : 0;
	write(data.fd, data.buf, data.i_b);
	va_end(data.ap);
	return ((int)data.len);
}
