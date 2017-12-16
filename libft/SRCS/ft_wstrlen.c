#include "libft.h"

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
	ft_putstr("in wstrlen -> ");//
	while (*s)
		len += ft_wcharlen(*s++);
	ft_putstr("end wstrlen -> ");//
	return (len);
}
