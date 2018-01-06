/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribuate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:06 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/06 21:15:03 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_att_init(t_data *data)
{
	ft_buffering(data, data->ft - data->i, data->i);
	data->bd = 0;
	data->prec = 1;
	data->min_s = 0;
}

void			ft_attribuate(t_data *data)
{
	ft_att_init(data);
	if (!*++data->ft)
	{
		data->i = 0;
		return ;
	}
	while (ft_strchr(".0123456789# +-*hjlz", *data->ft))
	{
		ft_flags_parser(data);
		ft_precision_parser(data);
		ft_len_mod_parser(data);
	}
	data->bd & POS ? data->bd &= ~SPACE : 0;
	if (ft_strchr("BCDOSUX", *data->ft))
		data->bd |= *data->ft != 'X' ? LONG : MAJ;
	//printf("2 min_s = %d\n", data->min_s);//
	ft_put_type(data);
	data->i = -1;
}
