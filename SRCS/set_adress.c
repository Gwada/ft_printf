#include <ft_printf.h>

void		ft_set_adress(t_data *d)
{
	void	*ptr;

	ptr = va_arg(d->ap, void *);
	d->B_D &= ~DIESE;
	d->min_s -= d->B_D & ZERO ? 2 : 0;
	d->filler = d->c_len > d->min_s - 3 ? 0 : d->min_s - d->c_len - 3;
	d->B_D |= DIESE;
	d->B_D |= POINTEUR;
	ft_itoa_base_p(d, (long long)ptr, 16);
}
