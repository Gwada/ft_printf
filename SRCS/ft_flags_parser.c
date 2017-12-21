/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:05:44 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/21 10:49:49 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_parser(t_data *data)
{
	//ft_putstr("|in flag pars -> ");
	while ((data->i_f = ft_strchri("# +-0*", *data->ft)) >= 0 && *++data->ft)
		data->B_D |= 1 << data->i_f;
	if (data->B_D & NEG && !(data->B_D & STAR))
		data->B_D &= ~ZERO;
	if (data->B_D & POS)
		data->B_D &= ~SPACE;
	if (data->B_D & STAR)
		ft_star_gestion(data);//
	//ft_putstr("<- out flag pars|\n");//
}
