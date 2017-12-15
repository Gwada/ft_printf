/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:22:47 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/15 18:58:23 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_type(t_data *data)
{
	if (*data->form == 's' || *data->form == 'S')
		ft_putstr_printf(data);
	/*else if (*data->form == 'c' || *data->form == 'C')
		ft_putchar_printf(data);
	else if ()i*/
	else if (*data->form == 'b')
		ft_putbin(data);
}
