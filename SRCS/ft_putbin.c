/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:30:45 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/14 20:48:12 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbin(t_data *data)
{
	unsigned	*c;
	unsigned	mask;
	unsigned	i;

	mask = ~(~0U >> 1);
	i = 0;
	c = (unsigned*)va_arg(data->ap, unsigned*);
	while(mask > 0)
	{
		//if (*c & mask)
		//{
	//		while (mask > 0)
	//		{
				if (i && !(i % 4))
					ft_buffering(data, " ", 1);
				if (i && !(i % 8))
					ft_buffering(data, " ", 1);
				ft_buffering(data, *c & mask ? "1" : "0", 1);
				mask >>= 1;
				++i;
	//		}
		//	ft_buffering(data, " ", 1);
	//	}
	//	++i;
	//	++c;
	}
}
