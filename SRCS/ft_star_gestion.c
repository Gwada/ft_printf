/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:11:04 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 19:47:28 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_star_gestion(t_data *data)
{
	ft_putstr("in star gest -> ");
	data->B_D &= ~STAR;
	if ((data->i_f = (int)va_arg(data->ap, int)) < 0)
	{
		data->B_D |= NEG;
		data->i_f *= -1;
	}
	else
		data->B_D &= ~NEG;
	if (!(data->B_D & PREC))
		data->min_s = data->i_f;
	else
	{
		data->prec = data->B_D & NEG ? 0 : data->i_f;//
		data->B_D = data->i_f ? data->B_D & ~PREC : data->B_D | PREC;//
	}
	ft_putstr("end star gest -> ");
}
