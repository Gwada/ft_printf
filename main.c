# include <stdio.h>
//# include <limits.h>
# include "./Includes/ft_printf.h"

//int		main (int argc, char **argv)
//{
	//char *s = "start aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa end\n";
	//char *s1 = "Dimitri";
	//char *s2 = "today";
	//printf("/**********/\n");
	//printf("/* printf */\n");
	//printf("/**********/\n");

	//printf("ret = %d\n\n", printf(s));
	//printf("ret = %d\n\n\n\n", printf("Bonjour %s, comment vas-tu %s?\n%c\n", s1, s2, "fdgf"));

	//printf("\n/*************/\n");
	//printf("/* ft_printf */\n");
	//printf("/*************/\n");

	//printf("ret = %d\n\n\n\n", ft_printf("Bonjour %s, comment vas-tu %s?\n%c\n", s1, s2, "fdgf"));
void	put_binary(unsigned c)
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
	}/*
	printf ("\n(f = %d) & 1 << 3\n", f);
	put_binary(f & 1 << 3);
	printf("\n!(f & 1 << 5))\n");
	put_binary(f & 1 << 5);
	printf("\nf &= ~1 << 4\n");
	printf("\nif (f & 1 << 3 && !(f & ))\n");
	(f & 1 << 3 && !(f & 1 << 5)) ? f &= ~(1 << 4) : 0;
	put_binary(f);
	printf("%i|", 5);*/
	//f = 32 | = 1 << 15;
	//put_binary(32 | (f & 1 << 4));
	return (0);
}
