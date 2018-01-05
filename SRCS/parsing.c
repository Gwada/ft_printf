#include "ft_printf.h"

void	ft_flags_parser(t_data *data)
{
	while ((data->i_f = ft_strchri("# +-0*", *data->ft)) >= 0 && *++data->ft)
		data->B_D |= 1 << data->i_f;
	if (data->B_D & NEG && !(data->B_D & STAR))
		data->B_D &= ~ZERO;
	if (data->B_D & POS)
		data->B_D &= ~SPACE;
	if (data->B_D & STAR)
		ft_star_gestion(data);//
}

void	ft_star_gestion(t_data *data)
{
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
}

void	ft_precision_parser(t_data *data)
{
	data->min_s = 0;
	if (*data->ft >= '1' && *data->ft <= '9')
	{
		data->min_s = MAX(1, ft_atoi_p(data->ft));
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
	}
	if (*data->ft == '.')
	{
		++data->ft;
		data->prec = MAX(ft_atoi_p(data->ft), 0);
		while (*data->ft >= '0' && *data->ft <= '9')
			++data->ft;
		data->B_D |= PREC;
	}
}

void	ft_len_mod_parser(t_data *data)
{
	while (42)
	{
		if (*data->ft == 'l')
			data->B_D |= (data->ft[1] == 'l' && ++data->ft) ? LONGX2 : LONG;
		else if (*data->ft == 'h')
			data->B_D |= (data->ft[1] == 'h' && ++data->ft) ? SHORTX2 : SHORT;
		else if (*data->ft == 'j')
			data->B_D |= INTMAX;
		else if (*data->ft == 'z')
			data->B_D |= SIZE_T;
		/*else if (*data->ft == 'q')//
			data->B_D |= LONGX2;*///
		else
			break ;
		++data->ft;
	}
}

void	ft_put_type(t_data *data)
{
	//printf("|in put type c = ->%c<-\n", *data->ft);//
	//printf("[%c][*%c][%c][%c]\n",*(data->ft-1),*data->ft,*(data->ft+1),*(data->ft+2));//
	if (ft_strchr("sS", *data->ft))
		ft_set_string(data);
	else if (ft_strchr("cC", *data->ft))
		ft_set_car(data, va_arg(data->ap, int));
	else if (*data->ft == 'n')
		ft_set_len(data);
	else if (ft_strchr("dDi", *data->ft))
		ft_set_signed(data);
	else if (*data->ft == 'm')
		ft_set_error(data);
	else if (*data->ft == 'p')
		ft_set_adress(data);
	else if (ft_strchr("fF", *data->ft))
		ft_set_float(data, (double)va_arg(data->ap, double));
	else if (ft_strchr("bBoOuUxX", *data->ft))
		ft_set_base(data);
	else
		ft_no_types(data);
	//printf("[%c][*%c][%c]\n",*(data->ft-1),*data->ft,*(data->ft+1));//
//	printf("<- end put type |\n");//
}
