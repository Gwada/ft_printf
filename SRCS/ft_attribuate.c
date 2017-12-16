/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribuate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:06 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/16 20:24:49 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_attribuate(t_data *data)
{
	ft_putstr("c = %\nin attribuate ->");//
	ft_attribuate_init(data);
	if (!*++data->ft)
	{
		++data->i;
		return ;
	}
	ft_flags_parser(data);//
	ft_precision_parser(data);
	ft_len_mod_parser(data);//
	ft_flags_parser(data);
	ft_put_type(data);
	ft_putstr("<- end attribuate\n\n");//
}
