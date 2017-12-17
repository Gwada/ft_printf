/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:47:34 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/17 18:25:59 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_parser(t_data *data)
{
	ft_putstr("|in prec pars ->\n");//
	if (*data->ft >= '1' && *data->ft <= '9')
	{
		ft_putstr("|1 <= p | -> before min_s = |");//
		ft_putnbr(data->min_s);//
		ft_putstr("| -> after min_s = |");//
		data->min_s = MAX(1, ft_atoi(data->ft));
		ft_putnbr(data->min_s);//
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
		ft_putstr("| -> ");//
	}
	if (*data->ft == '.')
	{
		ft_putstr("c = |.|\n");//
		++data->ft;
		ft_putstr("before atoi precision = |");//
		ft_putnbr(data->prec);//
		ft_putstr("|\nafter atoi et MAX, precision = |");//
		data->prec = MAX(ft_atoi(data->ft), 0);
		ft_putnbr(data->prec);//
		ft_putstr("|\n");//
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
		data->B_D |= PREC;
		ft_putstr("c = |");//
		ft_putchar(*data->ft);//
		ft_putstr("|\n");//
	}	
	ft_putstr("\n<- end prec pars|\n\n");//
}
