#include "libft.h"

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
//	printf("in wstrlen ->\n");//
	while (*s != L'\0')
	{
		//printf ("before wcarlen\n");
		len += ft_wcharlen(*s);
		//printf("ws = %zu\nout wcharlen\n", len);
		s++;
	}
//	printf("end wstrlen\n");//
	return (len);
}
