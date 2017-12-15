/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:44:57 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/14 20:48:20 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffering(t_data *data, const char *s, int len)
{
	int		i;

	i = -1;
	while (++i - len)
	{
		if (data->i_b == BUFF_SIZE)
		{
			write(data->fd, data->buf, BUFF_SIZE);
			ft_bzero(data->buf, BUFF_SIZE);
			data->i_b = 0;
		}
		data->buf[data->i_b++] = s[i];
		data->len++;
	}
}
