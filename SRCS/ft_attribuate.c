#include "ft_printf.h"

void	ft_attribuate(t_data *data)
{
	//ft_putstr("| in attribuate -> ");//
	if (!*++data->form)
	{
		++data->i;
		--data->form;
		return ;
	}
	ft_put_type(data);
	//ft_putstr("| end attribuate ");//
}
