#include "ft_printf.h"

static	int	ft_dtoa_buf(t_data *d, double n, long n2)
{
	int			len;
	int			c_n;
	char		*nb;

	len = d->c_len - d->prec - 1;
	c_n = d->c_len - len - 1;
	if (!(nb = (char*)malloc(sizeof(char) * d->c_len + 1)))
		return (0);
	while (c_n)
	{
		nb[len + c_n--] = n2 % 10 + '0';
		n2 /= 10;
	}
	d->prec > 0 ? nb[len] = '.' : 0;
	n2 = (long)(n < 0 ? -n : n);
	while (c_n < len)
	{
		nb[len - ++c_n] = n2 % 10 + '0';
		n2 /= 10;
	}
	((d->B_D & PREC && d->B_D & ZERO) || (d->B_D & SPACE)) ? *nb = ' ' : 0;
	n < 0 ? *nb = '-' : 0;
	(d->B_D & POS && n >= 0) ? *nb = '+' : 0;
	ft_buffering(d, nb, d->c_len);
	free(nb);
	return (1);
}

void			ft_set_float(t_data *data, double n)
{
	int			len;
	long		n2;
	long		tmp;
	double		dcl;

	data->B_D & ZERO ? data->prec = data->min_s : 0;
	!(data->B_D & PREC) ? data->prec = 6 : 0;
	len = data->prec > 0 ? 1 : 0;
	tmp = n < 0 ? -n : n;
	while (tmp && ++len)
		tmp /= 10;
	data->B_D & ZERO ? data->prec = data->min_s : 0;
	data->c_len = data->prec + len + (n < 0 ? 1 : 0);
	data->filler = data->c_len > data->min_s ? 0 : data->min_s - data->c_len;
	dcl = (n < 0.0f) ? (-n - (long)-n) : (n - (long)n);
	tmp = (long)data->prec;
	while (tmp-- + 1)
		dcl *= 10;
	dcl = ((long)dcl % 10 > 4) ? (dcl / 10 + 1) : dcl / 10;
	n2 = (int)dcl;
	ft_filler(data, 0);
	if (!(ft_dtoa_buf(data, n, n2)))
		return (ft_error(data, 0));
	ft_filler(data, 1);
}
