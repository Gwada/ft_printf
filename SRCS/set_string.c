/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:38:47 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/09 20:08:08 by dlavaury         ###   ########.fr       */
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
	data->bd & PREC ? len = MIN(data->prec, len) : 0;
	data->filler = (data->min_s - len) > 0 ? data->min_s - len : 0;
	ft_filler(data, 0);
	ft_buffering(data, s, len);
	ft_filler(data, 1);
}

/*static	void	init(t_data *d, int wlen){
	printf("--- init ---\n");//
	printf("\twlen\t\t= %d\n", wlen);//
	printf("\tchamp min\t= %d\n", d->min_s);//
	printf("\tprecision\t= %d\n\n", d->prec);//
}
static	void	set(t_data *d, int wlen){
	printf("--- set ---\n");//
	printf("\tMIN -> wlen\t= %d\n", wlen);//
	printf("\tMAX -> filler\t= %d\n\n", d->filler);//
}
static	void	while_to_remove(t_data *d, int i, int c_len, int wlen, wchar_t ws){
	printf ("--- while ---\n");
	printf("%d) \t| %C |\n", i, ws);
	printf("\twc_len = %d\t", c_len);//
	//printf("champ min = %d\t", d->min_s);//
	printf("wlen = %d\t", wlen);//
	printf("precision = %d\n\n", d->prec);//
}
static	void	end_while(t_data *d, int c_len, int wlen){
	printf ("\t->ajout car\n");
	printf("\tc_len = %d\t", c_len);//
	//printf("champ min = %d\t", d->min_s);//
	printf("wlen = %d\t", wlen - c_len);//
	printf("precision = %d\n\n", d->prec);//
	printf("--------------------------------------------------------------- end\n");//
}
static	void	verif_error(t_data *d, int c_len, wchar_t ws, int wlen){
	printf("--- verif error ---\n");//
	printf("\tdata->prec = %d\t", d->prec);//
	printf("c_len = %d\t", c_len);//
	printf("ws = %d\t\t", ws);//
	printf("wcar = %d\n", wlen);//
	printf("--- end verif error ---\n");//
}
*/void			ft_putwstr_p(t_data *d)
{
	int			len;
	int			wlen;
	int			c_len;
	wchar_t		*ws;

	if (!(ws = va_arg(d->ap, wchar_t*)))
		ws = L"(null)";//
	wlen = ft_wstrlen(ws);
//															init(d, wlen);//
	d->bd & PREC ? wlen = MIN(d->prec, wlen) : 0;
	d->filler = MAX(d->min_s - wlen, 0);
	d->bd = d->min_s > d->prec ? d->bd & ~PREC : d->bd | PREC;
//															set(d, wlen);//
	len = 0;
	c_len = 0;
	ft_filler(d, 0);
//															int i = 0;
//															printf("\t--- start while ---\n");//
	while ((d->car = *ws++) && (wlen -= c_len) >= 0)
	{
		c_len = ft_wcharlen(d->car);
//															while_to_remove(d, ++i, c_len, wlen, d->car);
		c_len <= wlen ? ft_putwchar_p(d, d->car, wlen, c_len) : 0;
		len += c_len;
		if ((!c_len && wlen) || (!c_len && d->prec > len))
		{
//															verif_error(d, c_len, d->car, wlen);
			return(ft_error(d, d->i_b + len));
		}
//															end_while(d, c_len, wlen);
	}
	c_len > wlen ? d->filler += wlen : 0;
//	printf("\t--- end boucle ---\n\ndata->filler = %d\n--- final end ---\n\n", d->filler);//
	ft_filler(d, 1);
}
