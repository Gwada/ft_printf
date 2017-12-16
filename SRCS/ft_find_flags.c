/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:30:42 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 19:36:23 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_flags(t_data *data)
{
	ft_putstr("in find flag -> ");
	while (*data->ft && (data->i_f = ft_strchri("# +-0*", *data->ft)) >= 0)
	{
		data->B_D |= 1 << data->i_f;
		++data->ft;
	}
	ft_putstr("out find flag -> ");
}
