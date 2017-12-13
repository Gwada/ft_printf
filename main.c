# include <stdio.h>
//# include <limits.h>
# include "./Includes/ft_printf.h"

//int		main (int argc, char **argv)
//{
//	printf("/**********/\n");
//	printf("/* printf */\n");
//	printf("/**********/\n");
//	printf("ret = %d\n\n", printf("Bonjour %s, comment vas-tu %s?\n", "Dimitri", "aujourd'hui"));

//	printf("\n/*************/\n");
//	printf("/* ft_printf */\n");
//	printf("/*************/\n");

//	printf("ret = %d\n\n\n\n", ft_printf("Bonjour %s, comment vas-tu%s?\n", "Dimitri", " aujourd'hui"));
//	printf("\nret = %d\n", ft_printf("%"));

void	put_binary(void *c)
{
	unsigned mask = ~(~0U >> 1);
	unsigned i = 0;

	mask >>= 25;
	while (mask > 0)
	{
		//if (i && !(i % 4))
		//	ft_printf(" ");
		ft_putchar(((unsigned)c & mask) ? '1' : '0');
		mask >>= 1;
		++i;
	}
}

int		main(void)
{
	char *str = "ceci est un test";
	while (*str)
	{
		put_binary((void*)&str++);
		ft_printf(" ");
	}
	ft_printf("\n");
	return (0);
}
