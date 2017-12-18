/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 20:12:25 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 14:04:07 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_types(t_data *data)
{
	printf("in no types\nmin_s = %d\n", data->min_s);
//	if (data->min_s)
//	{
//		ft_putstr("il faut combler");
//		//ft_get_size();
//	}
	data->filler = data->min_s - 1;
	ft_filler(data, 0);
	ft_buffering(data, data->ft, 1);
//	while (--data->min_s)
//		ft_buffering(data, " ", 1);
	ft_filler(data, 1);
	ft_putstr("<- end no types ");
}