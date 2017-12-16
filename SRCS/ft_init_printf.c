/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:22:51 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 20:26:39 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_printf(t_data *data, const char *s, int fd)
{
	ft_bzero(data, sizeof(*data));
	data->ft = (char*)s;
	data->fd = fd;
}
