/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:30:53 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 20:25:00 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(t_data *data)
{
	ft_putstr("in putstr pri -> ");//
	int		c_s;
	int		len;
	wchar_t	*s;

	if (!(data->s = (wchar_t*)va_arg(data->ap, wchar_t*)))
		return (ft_buffering(data, "(null)", 6));
	len = (int)ft_wstrlen((unsigned*)s);
	ft_putstr("->wlen = ");
	ft_putnbr(len);
	ft_putstr("<-\n");
	ft_putstr("end putstr pri -> ");//

}
