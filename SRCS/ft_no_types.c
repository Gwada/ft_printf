/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 20:12:25 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/08 19:29:11 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_types(t_data *data)
{
	if ((data->filler = data->min_s - 1) > 0)
		ft_filler(data, 0);
	//printf("c = %c|%c|\n", *(data->ft - 1), *data->ft);//
	ft_buffering(data, data->ft, 1);
	if (data->filler > 0)
		ft_filler(data, 1);
}
