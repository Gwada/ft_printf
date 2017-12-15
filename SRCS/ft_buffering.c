/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:44:57 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/15 18:58:09 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffering(t_data *data, const void *s, int len)
{
	int		i;
	char	*src;
	//ft_putstr("in\n");
	i = -1;
	src = (char*)s;
	while (++i - len)
	{
		if (data->i_b == BUFF_SIZE)
		{
			write(data->fd, data->buf, BUFF_SIZE);
			ft_bzero(data->buf, BUFF_SIZE);
			data->i_b = 0;
		}
		data->buf[data->i_b++] = src[i];
		data->len++;
	}
	//ft_putstr("out\n");
}
