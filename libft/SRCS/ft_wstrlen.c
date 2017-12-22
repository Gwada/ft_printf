#include "libft.h"

size_t		ft_wstrlen(wchar_t *s)
{
	size_t	wstrlen;

	wstrlen = 0;
	while (*s != L'\0')
		wstrlen += ft_wcharlen(*s++);
	return (wstrlen);
}
