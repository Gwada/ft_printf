#include "libft.h"

size_t	ft_wcharlen(unsigned c)
{
//	printf("in wcharlen->\n");
//	printf("c = %d\n", c);
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	return (4);
}
