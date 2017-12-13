# include <stdio.h>
//# include <limits.h>
# include "./Includes/ft_printf.h"

int		main (int argc, char **argv)
{
	printf("/**********/\n");
	printf("/* printf */\n");
	printf("/**********/\n");
	printf("ret = %d\n\n", printf("Bonjour %s, comment vas-tu %s?\n", "Dimitri", "T2opit"));

	printf("\n/*************/\n");
	printf("/* ft_printf */\n");
	printf("/*************/\n");

	printf("ret = %d\n\n\n\n", ft_printf("Bonjour %s, comment vas-tu%s?\n", "Dimitri", " T2opit"));
	return (0);
}
