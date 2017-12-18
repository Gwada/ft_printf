/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:30:42 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 14:36:03 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_flags(t_data *data)
{
	while ((data->i_f = ft_strchri("# +-0*", *data->ft)) >= 0 && *++data->ft)
	{
		//printf("c = |%c|\n", *(data->ft - 1));
		data->B_D |= 1 << data->i_f;
	}
	//ft_putstr("<- out find flag\n");//
}
