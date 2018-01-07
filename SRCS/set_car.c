/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_car.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 10:23:24 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/07 19:56:24 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwchar_p(t_data *data, wchar_t c, int size, int n_b)
{
	if (n_b <= size && n_b <= MB_CUR_MAX)
	{
		ft_bzero(data->u_c, 4);
		if (n_b == 1)
			data->u_c[0] = (char)c;
		else
		{
			if (n_b == 2)
				data->u_c[0] = ((c & (0x1F << 6)) >> 6) | 0xC0;
			else
			{
				if (n_b == 3)
					data->u_c[0] = ((c >> 12) & 0x0F) | 0xE0;
				else
				{
					data->u_c[0] = ((c >> 18) & 7) | 0xF0;
					data->u_c[1] = ((c >> 12) & 0x3F) | 0x80;
				}
				data->u_c[n_b - 2] = ((c >> 6) & 0x3F) | 0x80;
			}
			data->u_c[n_b - 1] = (c & 0x3F) | 0x80;
		}
		ft_buffering(data, data->u_c, n_b);
	}
}

void		ft_set_car(t_data *data)
{
	wchar_t	c;

	c = (*data->ft == '%') ? '%' : va_arg(data->ap, wchar_t);
	data->c_len = (data->bd & LONG || data->bd & LONGX2) ? ft_wcharlen(c) : 1;
	if ((!data->c_len || c < 0) && data->bd & LONG)
		return (ft_error(data, data->i));
	(data->filler = data->min_s - data->c_len) < 0 ? data->filler = 0 : 0;
	ft_filler(data, 0);
	if (*data->ft == '%')
	{
		ft_buffering (data, data->ft++, 1);
		data->error = 2;
	}
	else
		ft_putwchar_p(data, c, data->c_len, data->c_len);
	ft_filler(data, 1);
}
