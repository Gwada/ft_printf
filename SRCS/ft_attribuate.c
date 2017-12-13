#include "ft_printf.h"

void	ft_attribuate(t_data *data)
{
	++data->form;
	//ft_putstr("| in attribuate -> ");//
	/*if (!*data->form)
		return ;*/
	if (*data->form == 's')
	{
		data->s = (char*)va_arg(data->ap, unsigned*);
		ft_putstr_fd(data->s, data->fd);
		data->len += data->s ? (int)ft_strlen(data->s) - 1 : 5;
	}
//	ft_putsr("| end attribuate ");//
}
