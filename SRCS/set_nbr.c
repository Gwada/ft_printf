/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:30:24 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/07 20:40:12 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_set_signed(t_data *data)
{
	long long	nbr;

	if (data->bd & LONGX2 || data->bd & INTMAX)
		nbr = (long long)va_arg(data->ap, long long);
	else if (data->bd & LONG)
		nbr = (long long)va_arg(data->ap, long);
	else if (data->bd & SIZE_T)
		nbr = (long long)va_arg(data->ap, ssize_t);
	else if (data->bd & SHORT)
		nbr = (long long)((short)va_arg(data->ap, int));
	else if (data->bd & SHORTX2)
		nbr = (long long)((char)va_arg(data->ap, int));
	else
		nbr = (long long)va_arg(data->ap, int);
	ft_itoa_p(data, nbr, 0);
}
