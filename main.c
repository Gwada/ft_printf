/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:17:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/10 22:30:18 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "./Includes/ft_printf.h"

#define STR	"%15.1S", L"我是一只猫。"
#define STR1	"%---10.5ls", s

int				main(void)
{
	wchar_t	s[4];
	int		results[2];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	printf("/**********/\n");
	printf("/* printf */\n");
	printf("/**********/\n");
	results[0] = printf(STR);
	printf("\nret = %d\n\n", results[0]);
	printf("/*************/\n");
	printf("/* ft_printf */\n");
	printf("/*************/\n");
	results[1] = ft_printf(STR);
	printf("\nret = %d\n\n", results[1]);
	return (0);
}
