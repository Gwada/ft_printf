# include "ft_printf.h"

static void		ft_init(t_data *data, const char *format, int fd)
{
	ft_bzero(data, sizeof(*data));
	data->form = (char*)format;
	data->i = 0;
	data->fd = fd;
}

int				ft_printf(const char *format, ...)
{
	t_data	data;

	ft_init(&data, format, 1);
	va_start(data.ap, format);
	while (*data.form)
	{

		if (*data.form == '%')
		{
			write(data.fd, data.form - data.i, data.i);
			data.i = -1;
			//ft_putstr("||");//
			ft_attribuate(&data);
		}
		++data.i;
		++data.len;
		++data.form;
	}
	//ft_putstr("||");//
	write(data.fd, data.form - data.i, data.i);
	va_end(data.ap);
	return (data.len);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	t_data	data;

	ft_init(&data, format, fd);
	va_start(data.ap, format);
	while (*data.form)
	{

		if (*data.form == '%')
		{
			write(data.fd, data.form - data.i, data.i);
			data.i = -1;
			ft_attribuate(&data);
		}
		++data.i;
		++data.len;
		++data.form;
	}
	write(data.fd, data.form - data.i, data.i);
	va_end(data.ap);
	return (data.len);
}
