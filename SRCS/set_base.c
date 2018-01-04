#include "ft_printf.h"

static	char			ft_nb_bit(t_data *data)
{
	if (data->B_D & LONGX2 || *data->ft == 'B' || data->B_D & INTMAX)
		return ((char)sizeof(long long));
	if (data->B_D & LONG)
		return ((char)sizeof(long));
	else if (data->B_D & SIZE_T)
		return ((char)sizeof(size_t));
	else if (data->B_D & SHORT)
		return ((char)sizeof(short));
	else if (data->B_D & SHORTX2)
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

	if ((data->B_D & LONGX2) || (data->B_D & INTMAX) || (*data->ft == 'B'))
		n = (ULX2I)va_arg(data->ap, ULX2I);
	else if (data->B_D & LONG)
		n = (ULX2I)va_arg(data->ap, ULI);
	else if (data->B_D & SIZE_T)
		n = (ULX2I)va_arg(data->ap, size_t);
	else if (data->B_D & SHORT)
		n = (ULX2I)((USI)va_arg(data->ap, int));
	else if (data->B_D & SHORTX2)
		n = (ULX2I)((unsigned char)va_arg(data->ap, int));
	else
		n = (ULX2I)va_arg(data->ap, int);
	if (ft_strchr("bB", *data->ft))
		ft_put_bin_p(data, n);
	else
		ft_itoa_base_p(data, n, (ft_strchri_up("ou..x", *data->ft) + 4) << 1);
}
