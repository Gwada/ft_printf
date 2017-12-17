/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:53:27 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/17 21:02:44 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	*** LIBRAIRIES ***
*/

# include "../libft/Includes/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
**	*** MACCROS ***
*/

# define DIESE		(1 << 0)
# define SPACE		(1 << 1)
# define POS		(1 << 2)
# define NEG		(1 << 3)
# define ZERO		(1 << 4)
# define STAR		(1 << 5)
# define MAJ		(1 << 6)
# define SHORT		(1 << 7)
# define SHORTX2	(1 << 8)
# define LONG		(1 << 9)
# define LONGX2		(1 << 10)
# define INTMAX		(1 << 11)
# define SIZE_T		(1 << 12)
# define MIN_LEN	(1 << 13)
# define PREC		(1 << 14)
# define POINTEUR	(1 << 15)
# define MAX(a, b)	b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b)	a & ((a - b) >> 31) | b & (~(a - b) >> 31)

/*
**	*** STRUCTURES ***
*/

typedef struct		s_data
{
	int				i;
	int				fd;
	int				len;
	int				i_form;
	int				prec;
	int				min_s;
	int				filler;
	int				i_b;
	int				i_f;
	char			*ft;
	char			*s;
	char			buf[BUFF_SIZE + 1];
	short			B_D;
	wchar_t			*ws;
	va_list			ap;
	unsigned		car;

}					t_data;

/*
**	*** PROTOTYPES ***
*/

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
void				ft_init_printf(t_data *data, const char *s, int fd);
void				ft_attribuate(t_data *data);
void				ft_attribuate_init(t_data *data);
void				ft_flags_parser(t_data *data);
void				ft_find_flags(t_data *data);
void				ft_star_gestion(t_data *data);
void				ft_precision_parser(t_data *data);
void				ft_len_mod_parser(t_data *data);
void				ft_put_type(t_data *data);
//void				ft_putchar_printf(t_data *data);//
void				ft_set_string(t_data *data);
void				ft_putwstr_p(t_data *data);//
void				ft_putstr_p(t_data *data);//
void				ft_putbin(t_data *data);
void				ft_no_types(t_data *data);
void				ft_buffering(t_data *data, const void *s, int len);

# endif
