/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:38:47 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/21 20:42:42 by dlavaury         ###   ########.fr       */
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

static	void	ft_putwstring(t_data *d, unsigned c, int *w_l, int *c_l)
{
	((*c_l = ft_wcharlen((int)c)) == -1) ? d->error = -1 : 0;
	if (d->error)
		ft_error(d, *w_l);
	else
		ft_putwchar_p(d, c, *w_l, *c_l);
}

void			ft_putwstr_p(t_data *data)
{
	int			wlen;
	int			c_len;
	unsigned	*ws;

	if (!(ws = va_arg(data->ap, unsigned*)))//
		return(ft_buffering(data, "(null)", 6));//
	if (!(wlen = ft_wstrlen((unsigned*)ws)))
		data->error = -1;
	data->B_D & PREC ? wlen = MIN(data->prec, wlen) : 0;
	data->filler = MAX(data->min_s - wlen, 0);
	data->B_D = data->min_s > data->prec ? data->B_D & ~PREC : data->B_D | PREC;
	c_len = 0;
	ft_filler(data, 0);
	while (*ws && (wlen -= c_len) > 0 && !data->error)
		ft_putwstring(data, *(ws++), &wlen, &c_len);
	ft_filler(data, 1);
}

void		ft_set_string(t_data *data)
{
	if (data->B_D & LONG || data->B_D & LONGX2)
		ft_putwstr_p(data);
	else
		ft_putstr_p(data);
}
