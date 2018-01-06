/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:51:41 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/06 15:14:36 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_len(t_data *data)
{
	if (data->bd & LONGX2)
		*va_arg(data->ap, ULX2I*) = (ULX2I)data->len;
	else if (data->bd & LONG)
		*va_arg(data->ap, ULI*) = (ULI)data->len;
	else if (data->bd & SHORT)
		*va_arg(data->ap, int*) = (USI)data->len;
	else if (data->bd & SHORTX2)
		*va_arg(data->ap, int*) = (UC)data->len;
	else
		*va_arg(data->ap, int*) = (int)data->len;
}
