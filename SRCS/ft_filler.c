/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:16:06 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/21 09:41:18 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_filler(t_data *data, char opt)
{
	//ft_putstr("in filler ->\n");//
	if (!data->filler)
		return ;
	data->car = ' ' | (data->B_D & ZERO);
	if (!opt && !(data->B_D & NEG))
		while (data->filler--)
			ft_buffering(data, &data->car, 1);
	else if (opt && data->B_D & NEG)
		while (data->filler--)
			ft_buffering(data, &data->car, 1);
	//ft_putstr("<- end filler\n");//
}
