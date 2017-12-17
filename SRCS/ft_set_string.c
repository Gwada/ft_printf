/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:33:34 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/17 15:36:53 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_string(t_data *data)
{
	ft_putstr("in set string -> ");//
	if ((*data->ft == 's' && (data->B_D & LONG || data->B_D & LONGX2))
		|| *data->ft == 'S')
	{
		ft_putstr("|LONG ou S| -> ");
		if (!(data->ws = va_arg(data->ap, wchar_t*)))
			return (ft_buffering(data, "(null)", 6));
		//return (ft_putwstr_p(data));//
	}
	ft_putstr("|s| -> ");
	data->s = (char*)va_arg(data->ap, unsigned*);
	ft_putstr_p(data);
	ft_putstr("end set string -> ");//
}
