/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:44:57 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 16:48:18 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffering(t_data *data, const void *s, int len)
{
	//ft_putstr("in buff -> ");//
	int		i;
	char	*src;

	i = -1;
	src = (char*)s;
	while (++i - len)
	{
		//printf ("i = |%d|	i_b = |%d|	src[i] = %c\n", i, data->i_b, src[i]);
		if (data->i_b == BUFF_SIZE)
		{
			write(data->fd, data->buf, BUFF_SIZE);
			ft_bzero(data->buf, BUFF_SIZE);
			data->i_b = 0;
		}
		//printf("test\n");
		data->buf[data->i_b++] = src[i];
		data->len++;
	}
	//ft_putstr("out buff | ");
}
