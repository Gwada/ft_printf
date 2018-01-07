/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:53:27 by dlavaury          #+#    #+#             */
/*   Updated: 2018/01/07 20:50:28 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	*** LIBRAIRIES ***
*/

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

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
# define BUFF_SIZE	512
# define ULX2I		unsigned long long int
# define ULI		unsigned long int
# define USI		unsigned short int
# define UC			unsigned char
# define BASE8		(n || d->bd & POINTEUR) && d->bd & DIESE && b == 8 && !ext
# define BASE16		(n || d->bd & POINTEUR) && d->bd & DIESE && b == 16
# define VMAJ		d->bd & MAJ ? "0X" : "0x"

/*
**	*** STRUCTURES ***
*/

typedef struct		s_data
{
	int				i;
	int				fd;
	int				i_form;
	int				prec;
	int				min_s;
	int				filler;
	int				i_b;
	int				i_f;
	int				error;
	char			*ft;
	char			buf[BUFF_SIZE + 1];
	char			u_c[4];
	short			bd;
	va_list			ap;
	unsigned		car;
	int				c_len;
	long long int	len;
}					t_data;

/*
**	*** PROTOTYPES ***
*/

int					ft_atoi_p(const char *nptr);
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, unsigned c);
int					ft_strchri_up(const char *s, unsigned c);
size_t				ft_strlen(const char *s);
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
void				ft_attribuate(t_data *data);
void				ft_flags_parser(t_data *data);
void				ft_precision_parser(t_data *data);
void				ft_len_mod_parser(t_data *data);
void				ft_put_type(t_data *data);
void				ft_set_string(t_data *data);
size_t				ft_wcharlen(wchar_t c);
size_t				ft_wstrlen(wchar_t *ws);
void				ft_putwstr_p(t_data *data);
void				ft_putstr_p(t_data *data);
void				ft_set_car(t_data *data);
void				ft_putwchar_p(t_data *data, wchar_t c, int size, int n_b);
void				ft_set_signed(t_data *data);
void				ft_itoa_p(t_data *data, long long n, int len);
void				ft_itoa_buf(t_data *data, ULX2I n, int b, char *nb);
void				ft_itoa_base_p(t_data *data, ULX2I n, int b);
void				ft_set_float(t_data *data, double n);
void				ft_set_error(t_data *data);
void				ft_set_adress(t_data *data);
void				ft_set_base(t_data *data);
void				ft_set_len(t_data *data);
void				ft_no_types(t_data *data);
void				ft_filler(t_data *data, char opt);
void				ft_buffering(t_data *data, const void *s, int len);
void				ft_error(t_data *data, int to_remove);

#endif
