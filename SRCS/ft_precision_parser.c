/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:47:34 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 13:53:11 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_parser(t_data *data)
{
	//ft_putstr("|in prec pars ->\n");//
	if (*data->ft >= '1' && *data->ft <= '9')
	{
		//printf("|1 <= p | -> before min_s = |%d|\n", data->min_s);//
		data->min_s = MAX(1, ft_atoi(data->ft));
		//printf(" -> after min_s = |%d| end\n");//
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
	}
	if (*data->ft == '.')
	{
	//	ft_putstr("c = |.|\n");//
		++data->ft;
	//	printf("before atoi precision = |%d|\n", data->prec);//
		data->prec = MAX(ft_atoi(data->ft), 0);
	//	printf("after atoi et MAX, precision = |%d|\n", data->prec);//
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
		data->B_D |= PREC;
	//	printf("c = |%c|\n", *data->ft);//
	}	
//	ft_putstr("\n<- end prec pars|\n\n");//
}
