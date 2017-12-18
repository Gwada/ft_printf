/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:30:53 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/18 14:17:36 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_p(t_data *data)
{
	int		len;
	char	*s;

	//ft_putstr("in putstr ->\n");//
	//if (!(s = (char*)va_arg(data->ap, unsigned*)))-----------------------------//
	len = (s = (char*)va_arg(data->ap, unsigned*)) ? ft_strlen(s) : 6;
	data->B_D & PREC ? len = MIN(data->prec, len) : 0;
	data->filler = data->min_s - len > 0 ? data->min_s - len : 0;
	//printf("len = %d\ndata->filler = %d\ndata->min_s = %d\n", len, data->filler, data->min_s);//
	//data->car = 32 | (data->B_D & ZERO);
	//if (data->B_D & PREC)//

	//if (!(data->B_D & PREC))
	//{
		ft_filler(data, 0);
		if (!s)
		{
		//	ft_putstr("|!data->s| -> ");//
		//	if (!(data->B_D & ZERO))
		//	{
		//		ft_putstr("|!ZERO| -> ");//
				//while (!(data->B_D & NEG) && data->min_s-- > 6)
				//	ft_buffering(data, data->car, 1);
				ft_buffering(data, "(null)", 6);
				//while (data->B_D & NEG && data->min_s-- > 6)
					//ft_buffering(data, data->car, 1);
		//	}
		//	else
		//	{
		//		ft_putstr("|ZERO| -> ");//
		//		while (data->min_s--)
		//			ft_buffering(data, data->car, 1);
				//ft_buffering(data, "(null)", 6);
			//}
		}
		else
		{
			//ft_putstr("|data->s| -> ");//
			//int verif2 = (data->B_D & ZERO ) ? 48 : 32;
			//printf ("verif = %d\nverif2 = %d\ndata->filler = %d\n", verif, verif2, data->filler);
			ft_buffering(data, s, len);
		}
		ft_filler(data, 1);
//	}
//	else
//	{
//		printf("data->B_D & PREC\n");
//		while (data->min_s--)
//			ft_buffering(data, &data->car, 1);
//	}
	//ft_putstr("end putstr -> ");//
}
