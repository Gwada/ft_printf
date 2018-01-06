/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:31:19 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/06 21:06:15 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_itoa_p(t_data *d, long long n, int len)
{
	char		*nb;
	long long	tmp;

	tmp = n < 0 ? -n : n;
	while (tmp && ++len)
		tmp /= 10;
		//printf ("prec = %d\tmin_s = %d\tc_len = %d\tlen = %d\n",d->prec, d->min_s, d->c_len, len);//
	d->bd & ZERO && !(d->bd & POS) ? d->prec = d->min_s : 0;//
		//d->bd & ZERO && d->bd & POS ? d->prec = d->min_s : 0;//
		//printf ("prec = %d\n",d->prec);//
		//d->bd & ZERO && d->bd & POS ? printf ("1 test\n") :0;//
		//d->bd & ZERO && d->bd & POS && !(d->bd & PREC) ? d->prec = d->min_s : 0;
	d->bd & ZERO && d->bd & POS && d->bd & PREC ? (d->bd &= ~ZERO) : 0;
	((n < 0 || d->bd & POS || d->bd & SPACE) && d->bd & ZERO) ? --d->prec : 0;
	d->c_len = MAX(len, d->prec);
		//printf ("1 prec = %d\tmin_s = %d\tc_len = %d\n",d->prec, d->min_s, d->c_len);//
	(n < 0 || d->bd & POS || d->bd & SPACE) ? ++d->c_len : 0;
		//printf ("2 prec = %d\tmin_s = %d\tc_len = %d\n",d->prec, d->min_s, d->c_len);//
	(d->filler = d->min_s - d->c_len) < 0 ? d->filler = 0 : 0;
		//printf ("3 prec = %d\tmin_s = %d\tc_len = %d\n",d->prec, d->min_s, d->c_len);//
		//printf ("filler = %d\n",d->filler);//
	ft_filler(d, 0);
	if (!(nb = (char*)malloc(sizeof(char) * d->c_len + 1)))
		return (ft_error(d, 0));
	ft_itoa_buf(d, n < 0 ? -n : n, 10, nb);
	d->bd & SPACE ? *nb = ' ' : 0;
	n < 0 ? *nb = '-' : 0;
	d->bd & POS && n >= 0 ? *nb = '+' : 0;
	ft_buffering(d, nb, d->c_len);
	free(nb);
	ft_filler(d, 1);
}

void			ft_itoa_base_p(t_data *d, ULX2I n, int b)
{
	int			ext;
	char		*nb;
	ULX2I		tmp;

	d->c_len = 0;
	tmp = n;
	while (tmp && ++d->c_len)
		tmp /= b;
	(d->bd & ZERO && !(d->bd & PREC)) ? d->prec = d->min_s : 0;
	d->bd & ZERO && d->bd & PREC ? (d->bd &= ~ZERO) : 0;
	ext = d->c_len >= d->prec ? 0 : 1;
	d->c_len = MAX(d->c_len, d->prec);
	d->bd & DIESE && b == 8 && !ext ? --d->min_s : 0;
//	d->bd & DIESE && b == 8 && !n && d->B_D & PREC ? ++d->c_len : 0;
	d->bd & DIESE && b == 16 && !(d->bd & ZERO) ? d->min_s -= 2 : 0;
	d->filler = MAX(0, d->min_s - d->c_len);
	ft_filler(d, 0);
	BASE8 ? ft_buffering(d, "0", 1) : 0;
	BASE16 ? ft_buffering(d, VMAJ, 2) : 0;
	if (!(nb = (char*)malloc(sizeof(char) * d->c_len + 1)))
		return (ft_error(d, 0));
	ft_itoa_buf(d, n, b, nb);
	ft_buffering(d, nb, d->c_len);
	free(nb);
	ft_filler(d, 1);
}

void			ft_itoa_buf(t_data *d, ULX2I n, int b, char *nb)
{
	unsigned	c;
	int			len;

	if (n && !(d->bd & POINTEUR) && d->bd & ZERO && d->bd & DIESE
	&& b == 16 && !(d->bd & LONGX2) && d->c_len > 3)
		d->c_len -= 2;
	len = d->c_len;
	c = 'a' - 10 - ((d->bd & MAJ) >> 1);
	while (len--)
	{
		nb[len] = n % b + ((n % b < 10) ? '0' : c);
		n /= b;
	}
	d->bd & PREC && d->bd & ZERO ? *nb = ' ' : 0;
}
