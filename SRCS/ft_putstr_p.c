/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:30:53 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/17 15:36:51 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_p(t_data *data)
{
	ft_putstr("in putstr pri -> ");//
	if (!data->s)
	{
		ft_putstr("|!data->s| -> ");//
		if (!(data->B_D & ZERO))
		{
			ft_putstr("|ZERO| -> ");//
			while (data->min_s-- > 6)
				ft_buffering(data, " ", 1);
			ft_buffering(data, "(null)", 6);
		}
		else
		{
			ft_putstr("|!ZERO| -> ");//
			while (data->min_s--)
				ft_buffering(data, "0", 1);
		}
	}
	else
	{
		ft_putstr("|data->s| -> ");//
		ft_buffering(data, data->s, ft_strlen(data->s));
	}
	ft_putstr("end putstr pri -> ");//

}
