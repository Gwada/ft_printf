/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_mod_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:56:42 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 14:36:46 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_len_mod_parser(t_data *data)
{
//	ft_putstr("|in len mod ->\n");//
	while (42)
	{
		if (*data->ft == 'l')//
		{
//			ft_putstr("c = |l|\n");//
			data->B_D |= (data->ft[1] == 'l' && ++data->ft) ? LONGX2 : LONG;//
		}
		else if (*data->ft == 'h')//
		{
//			ft_putstr("c = |h|\n");//
			data->B_D |= (data->ft[1] == 'h' && ++data->ft) ? SHORTX2 : SHORT;//
		}
		else if (*data->ft == 'j')//
		{
//			ft_putstr("c = |j|\n");//
			data->B_D |= INTMAX;//
		}
		else if (*data->ft == 'z')//
		{
//			ft_putstr("c = |z|\n");//
			data->B_D |= SIZE_T;//
		}
		else
		{
//			ft_putstr("aucun ou dernier\n");//
			break ;
		}
		++data->ft;
	}
//	ft_putstr("<- end len mod|\n\n");//
}
