# include <stdio.h>
//# include <limits.h>
# include "./Includes/ft_printf.h"

#define STR		"u%4.2ss, %-1.s\n %---5.3s "
#define STR2	"%S"

int		main (void)
{
	char *s = "start aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa end";
	wchar_t s1[2];
	s1[0] = 'A', s1[1] = '\0';
	//char *s2 = "today";
	printf("/**********/\n");
	printf("/* printf */\n");
	printf("/**********/\n");

	printf("\nret = %d\n\n", printf(STR2, NULL));

	printf("/*************/\n");
	printf("/* ft_printf */\n");
	printf("/*************/\n");

	printf("\nret = %d\n", ft_printf(STR2, NULL));
	return (0);
}







/*void	put_binary(unsigned c)
{
	unsigned mask = ~(~0U >> 1);
	unsigned i = 0;

	while (mask > 0)
	{
		if (i && !(i % 4))
			ft_putstr(" ");
		ft_putchar((c & mask) ? '1' : '0');
		mask >>= 1;
		++i;
	}
	ft_putstr("\n");
}

int		main(void)
{
	int i = 5;
	int f = 0;
	//ft_putstr("\nvaleur binaire de depart\nf = ");
	put_binary(f);
	ft_printf("\n");
	while (i >= 0)
	{
		printf("(f = %d) |= (1 << (p->n = %d))\n", f, i);
		put_binary((f |= (1 << i--)));
	}
	return (0);
}*/
