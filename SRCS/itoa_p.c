#include "ft_printf.h"

void			ft_itoa_p(t_data *d, long long n, int len)
{
	char		*nb;
	long long	tmp;

	tmp = n < 0 ? -n : n;
	while (tmp && ++len)
		tmp /= 10;
	if ((n < 0 || d->B_D & POS || d->B_D & SPACE) && d->B_D & ZERO)
		--d->prec;
	d->c_len = MAX(len, d->prec);
	if (n < 0 || d->B_D & POS || d->B_D & SPACE)
		++d->c_len;
	d->filler = d->c_len > d->min_s ? 0 : d->min_s - d->c_len;
	ft_filler(d, 0);
	if (!(nb = (char*)malloc(sizeof(char) * d->c_len + 1)))
		return (ft_error(d, 0));
	ft_itoa_buf(d, n < 0 ? -n : n, 10, nb);
	d->B_D & SPACE ? *nb = ' ' : 0;
	n < 0 ? *nb = '-' : 0;
	d->B_D & POS && n >= 0 ? *nb = '+' : 0;
	ft_buffering(d, nb, d->c_len);
	free(nb);
	ft_filler(d, 1);
}

void			ft_itoa_base_p(t_data *d, ULX2I n, int b)
{
	int			ext;
	char		*nb;
	ULX2I		tmp;

	d->c_len = 0;
	tmp = n;
	while (tmp && ++d->c_len)
		tmp /= b;
	d->B_D & ZERO ? d->prec = d->min_s : 0;
	ext = d->c_len >= d->prec ? 0 : 1;
	d->c_len = MAX(d->c_len, d->prec);
	d->B_D & DIESE && b == 8 && !ext ? --d->min_s : 0;
	d->B_D & DIESE && b == 8 && !n && d->B_D & PREC ? ++d->c_len : 0;
	d->B_D & DIESE && b == 16 && !(d->B_D & ZERO) ? d->min_s -= 2 : 0;
	d->filler = MAX(0, d->min_s - d->c_len);
	ft_filler(d, 0);
	BASE8 ? ft_buffering(d, "0", 1) : 0;
	BASE16 ? ft_buffering(d, d->B_D & MAJ ? "0X" : "0x", 2) : 0;
	if (!(nb = (char*)malloc(sizeof(char) * d->c_len + 1)))
		return (ft_error(d, 0));
	ft_itoa_buf(d, n, b, nb);
	ft_buffering(d, nb, d->c_len);
	free(nb);
	ft_filler(d, 1);
}

void			ft_itoa_buf(t_data *d, ULX2I n, int b, char *nb)
{
	unsigned	c;
	int			len;

	if (n && !(d->B_D & POINTEUR) && d->B_D & ZERO && d->B_D & DIESE
	&& b == 16 && !(d->B_D & LONGX2) && d->c_len > 3)
		d->c_len -= 2;
	len = d->c_len;
	c = 'a' - 10 - ((d->B_D & MAJ) >> 1);
	while (len--)
	{
		nb[len] = n % b + ((n % b < 10) ? '0' : c);
		n /= b;
	}
	d->B_D & PREC && d->B_D & ZERO ? *nb = ' ' : 0;
}
