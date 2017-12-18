/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:33:34 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 16:48:12 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_string(t_data *data)
{
	//cc

	//c = *data->ft;
	//ft_putstr("in set string -> ");//
//	if (*data->ft == 'S' || (data->B_D & LONG || data->B_D & LONGX2))
//	{
//		ft_putstr("|LONG ou S| -> ");
		//ft_putwstr_p(data);//
	//}
	   *data->ft == 'S' || (LONGCHECK) ? ft_putwstr_p(data) : ft_putstr_p(data);
	//else
	//	ft_putstr_p(data);
//	ft_putstr("end set string -> ");//
}
