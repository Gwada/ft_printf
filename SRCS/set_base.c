/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:28:05 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/06 15:15:48 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char			ft_nb_bit(t_data *data)
{
	if (data->bd & LONGX2 || data->bd & INTMAX)
		return ((char)sizeof(long long));
	if (data->bd & LONG || *data->ft == 'B')
		return ((char)sizeof(long));
	else if (data->bd & SIZE_T)
		return ((char)sizeof(size_t));
	else if (data->bd & SHORT)
		return ((char)sizeof(short));
	else if (data->bd & SHORTX2)
		return ((char)sizeof(char));
	return ((char)sizeof(int));
}

static void				ft_put_bin_p(t_data *data, ULX2I n)
{
	char				i;
	long long unsigned	mask;

	i = -1;
	mask = ~(~0LLU >> 1) >> (-(ft_nb_bit(data) * 8));
	while (mask)
	{
		if (++i && !(i % 8))
			ft_buffering(data, " ", 1);
		ft_buffering(data, n & mask ? "1" : "0", 1);
		mask >>= 1;
	}
}

void					ft_set_base(t_data *data)
{
	ULX2I				n;

	if ((data->bd & LONGX2) || (data->bd & INTMAX) || (*data->ft == 'B'))
		n = (ULX2I)va_arg(data->ap, ULX2I);
	else if (data->bd & LONG)
		n = (ULX2I)va_arg(data->ap, ULI);
	else if (data->bd & SIZE_T)
		n = (ULX2I)va_arg(data->ap, size_t);
	else if (data->bd & SHORT)
		n = (ULX2I)((USI)va_arg(data->ap, unsigned int));
	else if (data->bd & SHORTX2)
		n = (ULX2I)((unsigned char)va_arg(data->ap, unsigned int));
	else
		n = (ULX2I)va_arg(data->ap, unsigned int);
	if (ft_strchr("bB", *data->ft))
		ft_put_bin_p(data, n);
	else
		ft_itoa_base_p(data, n, (ft_strchri_up("ou..x", *data->ft) + 4) << 1);
}
