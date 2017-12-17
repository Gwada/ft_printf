/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:30:42 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/17 17:38:07 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_flags(t_data *data)
{
	while ((data->i_f = ft_strchri("# +-0*", *data->ft)) >= 0 && *++data->ft)
	{
		ft_putstr("c = |");//
		ft_putchar(*(data->ft - 1));//
		ft_putstr("|\n");//
		data->B_D |= 1 << data->i_f;
		//++data->ft;
	}
	ft_putstr("<- out find flag\n");//
}
