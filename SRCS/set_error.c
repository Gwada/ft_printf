#include "ft_printf.h"

void		ft_set_error(t_data *data)
{
	char	*s;

	if (!(s = strerror(errno)))
	{
		if (!(data->B_D & ZERO))
			ft_buffering(data, "(null)", 6);
		else
			while (data->min_s--)
				ft_buffering(data, "0", 1);
	}
	else
		ft_buffering(data, s, (int)ft_strlen(s));
}
