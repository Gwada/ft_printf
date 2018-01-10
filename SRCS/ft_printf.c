/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:00 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/10 22:27:04 by dlavaury         ###   ########.fr       */
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
	while (*data.ft && data.error >= 0)
	{
		if (*data.ft == '%')
		{
			*++data.ft ? ft_attribuate(&data) : 0;
			data.i = 0;
			if (!(*data.ft) || data.error)
				break ;
		}
		!data.error && *data.ft != '%' ? ft_buffering(&data, data.ft, 1) : 0;
		*data.ft != '%' ? ++data.i : 0;
		*data.ft != '%' ? ++data.ft : 0;
	}
	write(data.fd, data.buf, data.i_b);
	va_end(data.ap);
	return (data.error == -1 ? -1 : data.len);
}

void		ft_attribuate(t_data *data)
{
	data->bd = 0;
	data->prec = 1;
	data->min_s = 0;
	while (ft_strchr(".0123456789# +-*hjlqz", *data->ft))
	{
		ft_flags_parser(data);
		ft_precision_parser(data);
		ft_len_mod_parser(data);
		if (!(*data->ft))
			return ;
	}
	if (*data->ft)
	{
		data->bd & POS ? data->bd &= ~SPACE : 0;
		if (ft_strchr("BCDOSUX", *data->ft))
			data->bd |= *data->ft != 'X' ? LONG : MAJ;
		ft_put_type(data);
		++data->ft;
	}
}
