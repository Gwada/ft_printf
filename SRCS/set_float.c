#include "ft_printf.h"

static	void	ft_dtoa_buf(t_data *data, double n, long n2)
{
	int			len;
	int			c_n;
	char		*nb;

	len = data->c_len - data->prec - 1;
	c_n = data->c_len - len - 1;
	/*while (c_n--)
	{
	}*/
	printf("in dtoa\nlen = %d\nc_n = %d\n", len, c_n);
	printf("c_len = %d\ndata->prec = %d\n", data->c_len, data->prec);
}

void			ft_set_float(t_data *data)
{
	int			len;
	long		n2;
	long		tmp;
	double		n;
	double		dcl;

	n = (double)va_arg(data->ap, double);
	data->B_D & ZERO ? data->prec = data->min_s : 0;
	printf("in set float\ndata->prec = %d\n", data->prec);
	!(data->B_D & PREC) ? data->prec = 6 : 0;
	printf("data->prec = %d\n", data->prec);
	len = data->prec > 0 ? 1 : 0;
	tmp = n < 0 ? -n : n;
	while (tmp && ++len)
		tmp /= 10;
	data->B_D & ZERO ? data->prec = data->min_s : 0;
	data->c_len = data->prec + len + n < 0 ? 1 : 0;
	dcl = (n < 0.0f) ? (-n - (long)-n) : (n - (long)n);//
	while (data->prec-- >= 0)//
		dcl *= 10;//
	dcl = (long)dcl % 10 > 4 ? dcl / 10 + 1 : dcl / 10 + 1;
	n2 = (int)dcl;
	//ft_filler(data, 0);
	ft_dtoa_buf(data, n, n2);
	//ft_filler(data, 1);
}
