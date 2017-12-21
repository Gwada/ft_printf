/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribuate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:06 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/21 20:42:51 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_att_init(t_data *d)
{
	ft_buffering(d, d->ft - d->i, d->i);
	d->B_D = 0;
	d->prec = 1;
	d->min_s = 0;
}

void			ft_attribuate(t_data *data)
{
	//ft_putstr("c = %\n|in attribuate ->\n");//
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
	data->B_D & POS ? data->B_D &= ~SPACE : 0;
	if (ft_strchr("BCDOSUX", *data->ft))
		data->B_D |= *data->ft != 'X' ? LONG : MAJ;
	ft_put_type(data);
	data->i = -1;
	//ft_putstr("<- end attribuate|\n\n");//
}
