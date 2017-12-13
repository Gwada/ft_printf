#include "ft_printf.h"

void	ft_putstr_printf(t_data *data)
{
	data->s = (char*)va_arg(data->ap, unsigned*);
	ft_putstr_fd(data->s, data->fd);
	data->len += data->s ? (int)ft_strlen(data->s) - 1 : 5;
}
