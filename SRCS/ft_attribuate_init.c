/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribuate_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 09:45:08 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 14:18:56 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_attribuate_init(t_data *data)
{
	//ft_putstr("|in attr init -> ");//
	ft_buffering(data, data->ft - data->i, data->i);
	data->i = -1;
	data->B_D = 0;
	data->prec = 1;
	//ft_putstr("\n<- end attr init|\n\n");//
}
