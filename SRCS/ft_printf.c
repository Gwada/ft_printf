/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:00 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 20:24:06 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_data	data;

	ft_init_printf(&data, format, 1);
	va_start(data.ap, format);
	while (*data.ft)
	{
		//printf("%c\n", *data.ft);
		if (*data.ft == '%')
		{//
			//printf("go attr ->\n");//
			ft_attribuate(&data);
			//printf("out attr ->\n");//
		}//
		else if (*data.ft++ && ++data.i == BUFF_SIZE)
		{
			printf("i = %d = BUFF_SIZE go buff -> \n", data.i);//
			ft_buffering(&data, data.ft - data.i, BUFF_SIZE);
			data.i = 0;
			printf("i = %d out buff -> \n", data.i);//
		}
	}
	ft_putstr("end while go buff -> ");//
	ft_buffering(&data, data.ft - data.i, data.i);
	ft_putstr("final write \n\n");//
	write(data.fd, data.buf, ft_strlen(data.buf));
	va_end(data.ap);
	ft_putstr("ret = ");//
	ft_putnbrendl(data.len);
	ft_putstr("clear -> end\n");//
	return (data.len);
}
