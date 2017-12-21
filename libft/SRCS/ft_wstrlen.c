#include "libft.h"

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;
    size_t  n;

	len = 0;
    n = 0;
	while (*s != L'\0')
	{
		if (!(n = ft_wcharlen(*s++)))
            return (0);
        len += n;
	}
	return (len);
}
