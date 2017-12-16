/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:30:53 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 20:13:19 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(t_data *data)
{
	ft_putstr("in putstr pri -> ");
	if (!(data->s = (unsigned*)va_arg(data->ap, unsigned*)))
		ft_buffering(data, "(null)", 6);
	else
		ft_buffering(data, data->s, ft_strlen(data->s));
	ft_putstr("end putstr pri -> ");

}
