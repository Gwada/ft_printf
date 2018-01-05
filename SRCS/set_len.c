#include "ft_printf.h"

void	ft_set_len(t_data *data)
{
	if (data->B_D & LONGX2)
		*va_arg(data->ap, ULX2I*) = (ULX2I)data->len;
	else if (data->B_D & LONG)
		*va_arg(data->ap, ULI*) = (ULI)data->len;
	else if (data->B_D & SHORT)
		*va_arg(data->ap, int*) = (USI)data->len;
	else if (data->B_D & SHORTX2)
		*va_arg(data->ap, int*) = (UC)data->len;
	else
		*va_arg(data->ap, int*) = (int)data->len;
}
