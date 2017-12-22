/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:44:57 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/22 19:46:15 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_buffering(t_data *data, const void *s, int len)
{
	int		i;
	char	*src;

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
}

void		ft_error(t_data *data, int	to_remove)
{
	data->error = -1;
	while (to_remove-- && data->i_b)
	{
		data->buf[data->i_b--] = '\0';
		data->i--;
	}
	data->len = -1;
}
