/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribuate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:06 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/14 20:05:30 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_attribuate(t_data *data)
{
	//ft_putstr("| in attribuate -> ");//
	if (!*++data->form)
	{
		++data->i;
		--data->form;
		return ;
	}
	ft_put_type(data);
	//ft_putstr("| end attribuate ");//
}
