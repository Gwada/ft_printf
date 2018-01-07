/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:00 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/07 20:44:40 by dlavaury         ###   ########.fr       */
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

void		ft_attribuate(t_data *data)
{
	ft_buffering(data, data->ft++ - data->i, data->i);
	data->bd = 0;
	data->prec = 1;
	data->min_s = 0;
	if (!*data->ft && !(data->i = 0))
		return ;
	while (ft_strchr(".0123456789# +-*hjlz", *data->ft))
	{
		ft_flags_parser(data);
		ft_precision_parser(data);
		ft_len_mod_parser(data);
	}
	data->bd & POS ? data->bd &= ~SPACE : 0;
	if (ft_strchr("BCDOSUX", *data->ft))
		data->bd |= *data->ft != 'X' ? LONG : MAJ;
	ft_put_type(data);
	data->i = (data->error == 2 ? 0 : -1);
	(data->error == 2) ? data->error = 0 : 0;
}
