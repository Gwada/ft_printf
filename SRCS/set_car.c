/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_car.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 10:23:24 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/10 19:00:31 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwchar_p(t_data *data, wchar_t c, int size, int n_b)
{
	if (n_b <= size && n_b <= MB_CUR_MAX)
	{
		if (n_b == 1)
			data->wchar[0] = (char)c;
		else
		{
			if (n_b == 2)
				data->wchar[0] = ((c & (0x1F << 6)) >> 6) | 0xC0;
			else
			{
				if (n_b == 3)
					data->wchar[0] = ((c >> 12) & 0x0F) | 0xE0;
				else
				{
					data->wchar[0] = ((c >> 18) & 7) | 0xF0;
					data->wchar[1] = ((c >> 12) & 0x3F) | 0x80;
				}
				data->wchar[n_b - 2] = ((c >> 6) & 0x3F) | 0x80;
			}
			data->wchar[n_b - 1] = (c & 0x3F) | 0x80;
		}
		ft_buffering(data, data->wchar, n_b);
	}
}

void		ft_set_car(t_data *data, wchar_t c)
{
	data->c_len = (data->bd & LONG || data->bd & LONGX2) ? ft_wcharlen(c) : 1;
	//printf("%d\tset car -> dlen\t= %d\tclen\t= %d\n", data->i, data->len, data->c_len);
	if ((!data->c_len || c < 0) && data->bd & LONG)
	{
	//	printf("%d\t!!!!!error\twclen\t= 0\ts\t= >%s<\n", data->i, data->ft);
		//return (ft_error(data, data->i_b - data->i));
		return (ft_error(data, data->i));
	}
	//printf("%d\tgood ->add\n", data->i);
	if ((data->filler = data->min_s - data->c_len) < 0)
		data->filler = 0;
	ft_filler(data, 0);
	ft_putwchar_p(data, c, data->c_len, data->c_len);
	//printf("%d\treste = >%s<\n", data->i, data->ft);
	ft_filler(data, 1);
}
