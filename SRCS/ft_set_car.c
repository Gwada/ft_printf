#include "ft_printf.h"

void	ft_set_car(t_data *data, unsigned c)
{
	printf("in set car\n");//
	//data->c_len = data->B_D & LONG || data->B_D & LONGX2 ? ft_wcharlen(c) : 1;
	data->c_len = ft_wcharlen(c);
	if ((data->filler = data->min_s - data->c_len) < 0)
		data->filler = 0;
	printf("c = |%d| len = |%d| filler = |%d| min_s = |%d|\n", c, data->c_len, data->filler, data->min_s);//
	ft_filler(data, 0);
	ft_putwchar_p(data, c, data->c_len, data->c_len);
	//ft_filler(data, 1);
	printf("out set car\n");//
}
