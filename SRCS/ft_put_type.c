/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:22:47 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/17 21:02:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_type(t_data *data)
{//
	printf("|in put type c = ->%c<-\n", c);//
	if (ft_strchr("sS", *data->ft))
		ft_set_string(data);
	/*else if (ft_strchr("cC", *data->ft)
		ft_set_car(data);
	else if (ft_strchr("dDi", *data->ft))
		ft_set_integer(data);
	else if (ft_strchr("fF", *data->ft)
		ft_set_double(data);
	else if (*data->ft == 'b')
		ft_putbin(data);*/
	else
		ft_no_types(data);
	ft_putstr("<- end put type |");//
}
