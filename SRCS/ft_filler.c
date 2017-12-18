/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:16:06 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 14:22:36 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_filler(t_data *data, char opt)
{
	//ft_putstr("in filler ->\n");//
	data->car = ' ' | (data->B_D & ZERO);
	//printf("data->car = %c\n", data->car);//
	if (!opt && !(data->B_D & NEG))
		while (data->filler--)
			ft_buffering(data, &data->car, 1);
	else if (opt && data->B_D & NEG)
		while (data->filler--)
			ft_buffering(data, &data->car, 1);
	//ft_putstr("<- end filler\n");//
}
