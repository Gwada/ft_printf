/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:28:47 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/08 19:29:08 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_set_error(t_data *data)
{
	char	*s;

	if (!(s = ERROR(errno)))
	{
		if (!(data->bd & ZERO))
			ft_buffering(data, "(null)", 6);
		else
			while (data->min_s--)
				ft_buffering(data, "0", 1);
	}
	else
		ft_buffering(data, s, (int)ft_strlen(s));
}
