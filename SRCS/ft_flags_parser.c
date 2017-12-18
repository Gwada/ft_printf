/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:05:44 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 14:34:06 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_parser(t_data *data)
{
	//ft_putstr("|in flag pars ->\n");
	ft_find_flags(data);//
	if (data->B_D & NEG && !(data->B_D & STAR))
	{
	//	ft_putstr("- && !*\n");//
		data->B_D &= ~ZERO;
	}
	if (data->B_D & POS)
	{
	//	ft_putstr("+ -> B_D &= ~SPACE\n");//
		data->B_D &= ~SPACE;
	}
	if (data->B_D & STAR)
	{
	//	ft_putstr("*\n");//
		ft_star_gestion(data);//
	}
//	ft_putstr("<- out flag pars|\n\n");//
}
