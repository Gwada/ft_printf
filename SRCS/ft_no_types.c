/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 20:12:25 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/06 21:15:06 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_types(t_data *data)
{
	if ((data->filler = data->min_s - 1) > 0)
		ft_filler(data, 0);
	if (*data->ft == '%')
		ft_buffering(data, data->ft++, 2);
	else
		ft_buffering(data, data->ft, 1);
	if (data->filler > 0)
		ft_filler(data, 1);
}
