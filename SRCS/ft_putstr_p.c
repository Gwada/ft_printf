/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:30:53 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/17 21:02:33 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_p(t_data *data)
{
	int		len;

	ft_putstr("in putstr -> ");//
	if (!(data->s = (char*)va_arg(data->ap, unsigned*)))
	//if (data->B_D & PREC)
	{
		ft_putstr("|!data->s| -> ");//
		if (!(data->B_D & ZERO))
		{
			ft_putstr("|!ZERO| -> ");//
			while (!(data->B_D & NEG) && data->min_s-- > 6)
				ft_buffering(data, " ", 1);
			ft_buffering(data, "(null)", 6);
			while (data->B_D & NEG && data->min_s-- > 6)
				ft_buffering(data, " ", 1);
		}
		else
		{
			ft_putstr("|ZERO| -> ");//
			while (data->min_s--)
				ft_buffering(data, "0", 1);
			//ft_buffering(data, "(null)", 6);
		}
	}
	else
	{
		printf("len = %d\n", (len = ft_strlen(data->s)));//
		ft_putstr("|data->s| -> ");//
		if (data->B_D & PREC)
		ft_filler();
		ft_buffering(data, data->s, ft_strlen(data->s));
	}
	ft_putstr("end putstr -> ");//
}
