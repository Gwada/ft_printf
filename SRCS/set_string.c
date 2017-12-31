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

static	void	init_to_remove(t_data *d, int wlen){
	printf("--- init ---\n");//
	printf("\twlen\t\t= %d\n", wlen);//
	printf("\tprecision\t= %d\n", d->prec);//
	printf("\tchamp min\t= %d\n", d->min_s);//
	printf("--- end init ---\n\n--- set ---\n");//
}
static	void	set_to_remove(t_data *d, int wlen){
	printf("\tMIN -> wlen\t= %d\n", wlen);//
	printf("\tMAX -> filler\t= %d\n", d->filler);//
	printf("--- end set ---\n\n");//
}
static	void	while_to_remove(t_data *d, int i, int c_len, int wlen){
	printf("%d)\tc_len = %d\t", i, c_len);//
	printf("min_s = %d\t", d->min_s);//
	printf("filler = %d\t", d->filler);//
	printf("wlen = %d\t", wlen);//
	printf("prec = %d\n", d->prec);//
}
static	void	end_while(t_data *d, int len, int c_len){
	printf ("\t->ajout car");
	printf("\tlen = %d\n", len);//
	printf("---------------------------------------------------------------\n");//
}
static	void	verif_error(t_data *d, int c_len, unsigned *ws, int wlen){
	printf("--- verif error ---\n");//
	printf("\tdata->prec = %d\t", d->prec);//
	printf("c_len = %d\t", c_len);//
	printf("ws = %d\t", *ws);//
	printf("wlen = %d\n", wlen);//
	printf("--- end verif error ---\n");//
}

void			ft_putwstr_p(t_data *d)
{
																	printf("--- start ---\n");//
	int			len;
	int			wlen;
	int			c_len;
	wchar_t		*ws;

	if (!(ws = va_arg(d->ap, wchar_t*)))
		return(ft_buffering(d, "(null)", 6));//
	wlen = ft_wstrlen(ws);
																	init_to_remove(d, wlen);//
	d->B_D & PREC ? wlen = MIN(d->prec, wlen) : 0;
	d->filler = MAX(d->min_s - wlen, 0);
	d->B_D = d->min_s > d->prec ? d->B_D & ~PREC : d->B_D | PREC;
																	set_to_remove(d, wlen);//
	len = 0;
	c_len = 0;
	ft_filler(d, 0);
	int i = 0;
																	printf("--- while ---\n");//
	while (*ws && (wlen -= c_len) >= 0)
	{
		c_len = ft_wcharlen(*ws);
																	while_to_remove(d, i++, c_len, wlen);//
		if (c_len > wlen)
		{
			d->filler += wlen;
																	printf ("\t->break data->filler = %d\n", d->filler);//
			break;
		}
		len += c_len;
		if (!c_len && ((*ws && wlen) || (d->prec > wlen)))
		{
																	verif_error(d, c_len, ws, wlen);
			return(ft_error(d, d->min_s - len + c_len));
		}
		ft_putwchar_p(d, *ws, wlen, c_len);
		c_len ? ++ws : 0;
																	end_while(d, len, c_len);
	}
	printf("--- end boucle ---\n\ndata->filler = %d\n--- final end ---\n\n", d->filler);//
	ft_filler(d, 1);
}

void		ft_set_string(t_data *data)
{
	if (data->B_D & LONG || data->B_D & LONGX2)
		ft_putwstr_p(data);
	else
		ft_putstr_p(data);
}
