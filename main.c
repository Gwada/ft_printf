/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:17:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/07 20:50:20 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include "./Includes/ft_printf.h"

#define STR		STR1
#define STR1	"%#.o %#.0", 0, 310
#define STR2	"|% 20.12ld et % 05D% 4.8hi !|", 0x11ffaa147, 24, (short)-2345
#define STR3	"|%        00%Z|"

int		main (void)
{
	//wchar_t s[4];
	//setlocale(LC_ALL, "");
	/*s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';*/
	//char d = 0;
	printf("/**********/\n");
	printf("/* printf */\n");
	printf("/**********/\n");
	printf("\nret = %d\n\n", printf(STR));
	printf("/*************/\n");
	printf("/* ft_printf */\n");
	printf("/*************/\n");
	printf("\nret = %d\n", ft_printf(STR));
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
