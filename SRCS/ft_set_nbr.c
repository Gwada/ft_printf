#include "ft_printf.h"

void ft_set_nbr(t_data *data)
{
	long long nbr;

	if (data->B_D & LONGX2)
		nbr = (long long)va_arg(data->ap, long long);
	else if (data->B_D & LONG)
		nbr = (long long)va_arg(data->ap, long);
	else if (data->B_D & SHORT)
		nbr = (short)va_arg(data->ap, int);
	else if (data->B_D & SHORTX2)
		nbr = (char)va_arg(data->ap, int);
	else if (data->B_D & SIZE_T)
		nbr = (unsigned)va_arg(data->ap, size_t);
	else
		nbr = (long long)va_arg(data->ap, int);
	data->B_D & ZERO ? data->prec = data->min_s : 0;
	//ft_itoa_p(data, n, 0);
}
