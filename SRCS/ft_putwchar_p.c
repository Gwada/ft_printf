#include "ft_printf.h"

void	ft_putwchar_p(t_data *data, unsigned c, int size, int n_b)
{
	printf("in putwchar\nbreak!!!\n");//
	//return ;
	ft_bzero(data->u_c, 4);
	printf("after bzero\n");//
	//return ;
	if (c < 0x80)
		data->u_c[0] = ((c >> 0) & 0x7F) | 0x00;
	else if (c < 0x0800)
	{
		printf("2\n");//
		//return ;
		data->u_c[0] = ((c >> 6) & 0x1f) | 0xc0;
		//return ;
		data->u_c[1] = ((c >> 0) & 0x3f) | 0x80;
		//return ;
	}
	else if (c < 0x010000)
	{
		printf("3\n");//
		return ;
		data->u_c[0] = ((c >> 12) & 0x0F) | 0xE0;
		data->u_c[1] = ((c >> 6) & 0x3F) | 0x80;
		data->u_c[2] = ((c >> 0) & 0x3F) | 0x80;
		return ;
	}
	else if (c < 0x110000)
	{
		printf("4\n");//
		return ;
		data->u_c[0] = ((c >> 18) & 0x07) | 0xF0;
		data->u_c[1] = ((c >> 12) & 0x3F) | 0x80;
		data->u_c[2] = ((c >> 6) & 0x3F) | 0x80;
		data->u_c[3] = ((c >> 0) & 0x3F) | 0x80;
		return ;
	}
	printf("u_c = %s\n", data->u_c);//
	ft_buffering(data, data->u_c, size);
}
