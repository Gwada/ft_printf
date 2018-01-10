/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:00 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/10 18:08:31 by dlavaury         ###   ########.fr       */
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
//		printf("%d\t%s\n", data.i, data.ft);
		if (*data.ft == '%')
		{
//			printf("%d\tprintf\tc\t= %c\t(attri)\n", data.i, *data.ft);
			//ft_attribuate(&data);
			//printf ("c = %c c + 1 = %c\n", *data.ft, *(data.ft + 1));
			*++data.ft ? ft_attribuate(&data) : 0;
			data.i = 0;
			if (!(*data.ft) || data.error)
				break ;
		}
		//else if (*data.ft && ++data.i == BUFF_SIZE)
		//{
		//else
		//{
//			*data.ft != '%' ? printf("%d\tno %%\tc\t= %c\t(buf)\n", data.i, *data.ft) : 0;
			//ft_buffering(&data, data.ft - data.i, BUFF_SIZE);
			!data.error && *data.ft != '%' ? ft_buffering(&data, data.ft, 1) : 0;
			*data.ft != '%' ? ++data.i : 0;
			//ft_buffering(&data, data.ft, 1);
		//}
		*data.ft != '%' ? ++data.ft : 0;
		//++data.ft;
	}
	write(data.fd, data.buf, data.i_b);
	va_end(data.ap);
	return (data.error == -1 ? -1 : data.len);
	//return (data.len);
}

void		ft_attribuate(t_data *data)
{
//	printf("%d\tc = %%\ts\t= >%s<\t\t(attri)\n", data->i, data->ft);
	data->bd = 0;
	data->prec = 1;
	data->min_s = 0;
	while (ft_strchr(".0123456789# +-*hjlqz", *data->ft))
	{
//		printf("%d\tbf fp\tc\t= %c\n", data->i, *data->ft);
		ft_flags_parser(data);
//		printf("%d\tbf pp\tc\t= %c\n", data->i, *data->ft);
		ft_precision_parser(data);
//		printf("%d\tbf lmp\tc\t= %c\n", data->i, *data->ft);
		ft_len_mod_parser(data);
//		printf("%d\taf lmp\tc\t= %c\n", data->i, *data->ft);
		if (!(*data->ft))
			return ;
	}
	if (*data->ft)
	{
		data->bd & POS ? data->bd &= ~SPACE : 0;
		if (ft_strchr("BCDOSUX", *data->ft))
			data->bd |= *data->ft != 'X' ? LONG : MAJ;
	//printf ("c = %c\n", *data->ft);
		ft_put_type(data);
		++data->ft;
//		printf("%d\taf put\tc\t= %c\n", data->i, *data->ft);
	}
}
