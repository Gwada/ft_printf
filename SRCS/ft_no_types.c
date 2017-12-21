/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 20:12:25 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/21 09:28:58 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_types(t_data *data)
{
	//printf("in no types\nmin_s = %d\n", data->min_s);
	if ((data->filler = data->min_s - 1) > 0)
		ft_filler(data, 0);
	ft_buffering(data, data->ft, 1);
	if (data->filler > 0)
		ft_filler(data, 1);
	//ft_putstr("<- end no types\n");
}
