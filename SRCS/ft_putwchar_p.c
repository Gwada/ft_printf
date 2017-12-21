#include "ft_printf.h"

void	ft_putwchar_p(t_data *data, unsigned c, int size, int n_b)
{
	//printf("in putwchar\n");//
	if (n_b <= size && n_b <= MB_CUR_MAX)
	{
		ft_bzero(data->u_c, 4);
		if (n_b == 1)
			data->u_c[0] = (char)c;
		else
		{
			if (n_b == 2)
				data->u_c[0] = ((c & (0x1F << 6)) >> 6) | 0xC0;
			else
			{
				if (n_b == 3)
					data->u_c[0] = ((c >> 12) & 0x0F) | 0xE0;
				else
				{
					data->u_c[0] = ((c >> 18) & 7) | 0xF0;
					data->u_c[1] = ((c >> 12) & 0x3F) | 0x80;
				}
				data->u_c[n_b - 2] = ((c >> 6) & 0x3F) | 0x80;
			}
			data->u_c[n_b - 1] = (c & 0x3F) | 0x80;
		}
		ft_buffering(data, data->u_c, size);
	}
//	printf("end putwchar\n");//
}
