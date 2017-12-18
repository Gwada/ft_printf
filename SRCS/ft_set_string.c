#include "ft_printf.h"

void	ft_set_string(t_data *data)
{
	if (*data->ft == 'S' || (data->B_D & LONG || data->B_D & LONGX2))
		ft_putwstr_p(data);
	else
		ft_putstr_p(data);
}
