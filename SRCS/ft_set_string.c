/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:38:47 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/22 19:46:10 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_p(t_data *data)
{
	int			len;
	char		*s;

	if (!(s = (char*)va_arg(data->ap, unsigned*)))
		s = "(null)";
	len = s ? ft_strlen(s) : 6;
	data->B_D & PREC ? len = MIN(data->prec, len) : 0;
	data->filler = (data->min_s - len) > 0 ? data->min_s - len : 0;
	ft_filler(data, 0);
	ft_buffering(data, s, len);
	ft_filler(data, 1);
}

void			ft_putwstr_p(t_data *data)
{
	int			len;
	int			wlen;
	int			c_len;
	wchar_t		*ws;

	if (!(ws = va_arg(data->ap, wchar_t*)))//
		return(ft_buffering(data, "(null)", 6));//
	wlen = ft_wstrlen(ws);
//printf("wlen = %d\tdata->prec = %d\n", wlen, data->prec);
	data->B_D & PREC ? wlen = MIN(data->prec, wlen) : 0;
//printf("MIN -> wlen = %d\n", wlen);
	data->filler = MAX(data->min_s - wlen, 0);
	data->B_D = data->min_s > data->prec ? data->B_D & ~PREC : data->B_D | PREC;
//printf("MAX -> filler = %d\nmin_s = %d\nprec = %d\n\n",data->filler,data->min_s,data->prec);
	data->min_s > data->prec ? data->B_D &= ~ PREC : 0;
	len = 0;
	c_len = 1;
	ft_filler(data, 0);
	int i = 0;
	while (*ws && !data->error && c_len)
	{
		c_len = ft_wcharlen(*ws);

//printf("%d | c_len = %d | ", i++, c_len);
//printf("data->min_s = %d | ", data->min_s);
//printf("wlen = %d | data->prec = %d | ", wlen, data->prec);

		if(c_len && (len += c_len) <= wlen)
			ft_putwchar_p(data, *ws, wlen, c_len);

//printf("len = |%d|\n", len);

		if ((!c_len && len <= wlen)
		|| (data->B_D & PREC && data->prec > len && !c_len && *ws))
			return(ft_error(data, data->min_s - len + c_len));
		c_len ? ++ws : 0;
	}
//printf("end\n");
	ft_filler(data, 1);
}

void		ft_set_string(t_data *data)
{
	if (data->B_D & LONG || data->B_D & LONGX2)
		ft_putwstr_p(data);
	else
		ft_putstr_p(data);
}
