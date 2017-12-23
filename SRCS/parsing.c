#include "ft_printf.h"

void	ft_flags_parser(t_data *data)
{
	//printf("|in flag pars ->\n");
	while ((data->i_f = ft_strchri("# +-0*", *data->ft)) >= 0 && *++data->ft)
		data->B_D |= 1 << data->i_f;
	if (data->B_D & NEG && !(data->B_D & STAR))
		data->B_D &= ~ZERO;
	if (data->B_D & POS)
		data->B_D &= ~SPACE;
	if (data->B_D & STAR)
		ft_star_gestion(data);//
	//printf("<- out flag pars|\n");//
}

void	ft_star_gestion(t_data *data)
{
	printf("in star gest ->\n");
	data->B_D &= ~STAR;
	if ((data->i_f = (int)va_arg(data->ap, int)) < 0)
	{
		data->B_D |= NEG;
		data->i_f *= -1;
	}
	else
		data->B_D &= ~NEG;
	if (!(data->B_D & PREC))
		data->min_s = data->i_f;
	else
	{
		data->prec = data->B_D & NEG ? 0 : data->i_f;//
		data->B_D = data->i_f ? data->B_D & ~PREC : data->B_D | PREC;//
	}
	printf("end star gest ->\n");
}

void	ft_precision_parser(t_data *data)
{
	//printf("|in prec pars ->\n");//
	data->min_s = 0;
	if (*data->ft >= '1' && *data->ft <= '9')
	{
		//printf("|1 <= p | -> before min_s = |%d|\n", data->min_s);//
		data->min_s = MAX(1, ft_atoi(data->ft));
		//printf(" -> after min_s = |%d| end\n");//
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
	}
	if (*data->ft == '.')
	{
	//	printf("c = |.|\n");//
		++data->ft;
	//	printf("before atoi precision = |%d|\n", data->prec);//
		data->prec = MAX(ft_atoi(data->ft), 0);
	//	printf("after atoi et MAX, precision = |%d|\n", data->prec);//
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
		data->B_D |= PREC;
	//	printf("c = |%c|\n", *data->ft);//
	}	
	//printf(" <- end prec pars|\n");//
}

void	ft_len_mod_parser(t_data *data)
{
//	printf("|in len mod ->\n");//
	while (42)
	{
		if (*data->ft == 'l')//
		{
//			printf("c = |l|\n");//
			data->B_D |= (data->ft[1] == 'l' && ++data->ft) ? LONGX2 : LONG;//
		}
		else if (*data->ft == 'h')//
		{
//			printf("c = |h|\n");//
			data->B_D |= (data->ft[1] == 'h' && ++data->ft) ? SHORTX2 : SHORT;//
		}
		else if (*data->ft == 'j')//
		{
//			printf("c = |j|\n");//
			data->B_D |= INTMAX;//
		}
		else if (*data->ft == 'z')//
		{
//			printf("c = |z|\n");//
			data->B_D |= SIZE_T;//
		}
		else
		{
//			printf("aucun ou dernier\n");//
			break ;
		}
		++data->ft;
	}
//	printf("<- end len mod|\n\n");//
}

void	ft_put_type(t_data *data)
{
	//printf("|in put type c = ->%c<-\n", *data->ft);//
	if (ft_strchr("sS", *data->ft))
		ft_set_string(data);
	else if (ft_strchr("cC", *data->ft))
		ft_set_car(data, va_arg(data->ap, int));
	/*else if (ft_strchr("dDi", *data->ft))
		ft_set_integer(data);
	else if (ft_strchr("fF", *data->ft)
		ft_set_double(data);
	else if (*data->ft == 'b')
		ft_putbin(data);*/
	else
		ft_no_types(data);
//	printf("<- end put type |\n");//
}
