#include "ft_printf.h"

void	ft_put_type(t_data *data)
{
	ft_putstr("in put type\n");//
	if (*data->form = 's')
	ft_putstr("test\n");
		ft_putstr_printf(data);
}
