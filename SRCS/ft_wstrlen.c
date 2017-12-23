#include "ft_printf.h"

size_t		ft_wstrlen(wchar_t *ws)
{
	size_t	wstrlen;

	wstrlen = 0;
	while (*ws != L'\0')
		wstrlen += ft_wcharlen(*ws++);
	return (wstrlen);
}
