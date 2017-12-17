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
{
	char c = *data->ft;//
	printf("|in put type c = ->%c<-\n", c);//
	if (*data->ft == 's' || *data->ft == 'S')
		ft_set_string(data);
	/*else if (*data->ft == 'c' || *data->ft == 'C')
		ft_putchar_p(data->ap, unsigned);
	else if (*data->ft == 'n')
		*va_arg(data->ap, long long unsigned *) = data->len;//
	else if (*data->ft == 'b')
		ft_putbin(data);*/
	else
		ft_no_types(data);
	ft_putstr("<- end put type |");//
}
