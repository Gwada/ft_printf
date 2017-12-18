/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:33:34 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 14:18:31 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_string(t_data *data)
{
	//cc

	//c = *data->ft;
	//ft_putstr("in set string -> ");//
	/*if (data->B_D & PREC)
	{
		if (data->B_D & ZERO)
			while (data->min_s--)
				ft_buffering(data, "0", 1);
		else if (data->B_D & NEG)
			while (data->min_s--)
				ft_buffering(data, " ", 1);
		return ;
	}*/
	if (*data->ft == 'S' || (data->B_D & LONG || data->B_D & LONGX2))
	{
		ft_putstr("|LONG ou S| -> ");
		//ft_putwstr_p(data);//
	}
	else
	{
//		ft_putstr("|s| -> ");
		ft_putstr_p(data);
	}
//	ft_putstr("end set string -> ");//
}
