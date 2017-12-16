/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:22:51 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 19:24:40 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_printf(t_data *data, const char *s, int fd)
{
	//printf("in init printf\n");
	ft_bzero(data, sizeof(*data));
	data->ft = (char*)s;
	data->fd = fd;
	//printf("out init printf\n");
}