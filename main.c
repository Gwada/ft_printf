/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:17:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/08 19:29:25 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "./Includes/ft_printf.h"

#define STR	"|%zj|", 9223372036854775807

int				main(void)
{
	wchar_t	s[4];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	(void)s;
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
