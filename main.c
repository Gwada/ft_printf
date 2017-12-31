# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include "./Includes/ft_printf.h"

#define STR		"|%---13.15ls|\n", s
#define STR2	"|%025f|", d

int		main (void)
{
	/*wchar_t s[4];
	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';*/
	double d = -1275326;
	printf("/**********/\n");
	printf("/* printf */\n");
	printf("/**********/\n");
	printf("\nret = %d\n\n", printf(STR2));
	printf("/*************/\n");
	printf("/* ft_printf */\n");
	printf("/*************/\n");
	printf("\nret = %d\n", ft_printf(STR2));
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
