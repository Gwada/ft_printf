/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:47:34 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 20:05:07 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_parser(t_data *data)
{
	ft_putstr("|in prec pars -> ");//
	if (*data->ft >= '1' && *data->ft <= '9')
	{
		data->min_s = MAX(1, ft_atoi(data->ft));
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
	}
	if (*data->ft == '.')
	{
		++data->ft;
		data->prec = MAX(ft_atoi(data->ft), 0);
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
		data->B_D |= PREC;
	}	
	ft_putstr("end prec pars|\n\n");//
}
