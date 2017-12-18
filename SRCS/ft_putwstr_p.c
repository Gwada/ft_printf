#include "ft_printf.h"

void			ft_putwstr_p(t_data *data)
{
	printf("in putwstr ->\n");
	int			wlen;
	int			c_len;
	wchar_t		*ws;

	if (!(ws = va_arg(data->ap, wchar_t*)))//
		return(ft_buffering(data, "(null)", 6));//

	data->B_D & PREC ? wlen = MIN(data->prec, wlen) : 0;

	data->filler = MAX(data->min_s - wlen, 0);

	data->B_D = data->min_s > data->prec ? data->B_D & ~PREC : data->B_D | PREC;

	wlen = (int)ft_wstrlen((unsigned*)ws);

	printf ("set ws size ok\n");
	printf ("wlen = %d\n", wlen);
	printf("<- out putwstr\n");

	ft_filler(data, 0);
	ft_filler(data, 1);
}
