/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:53:27 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/22 19:46:35 by dlavaury         ###   ########.fr       */
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
	int				error;
	char			*ft;
	char			buf[BUFF_SIZE + 1];
	char			u_c[4];
	short			B_D;
	va_list			ap;
	unsigned		car;
	unsigned		c_len;
}					t_data;

/*
**	*** PROTOTYPES ***
*/

int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
char				*ft_itoa(int n);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, unsigned c);
size_t				ft_strlen(const char *s);
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
void				ft_attribuate(t_data *data);
void				ft_flags_parser(t_data *data);
void				ft_star_gestion(t_data *data);
void				ft_precision_parser(t_data *data);
void				ft_len_mod_parser(t_data *data);
void				ft_put_type(t_data *data);
void				ft_set_string(t_data *data);
size_t				ft_wcharlen(wchar_t c);
size_t				ft_wstrlen(wchar_t *ws);
void				ft_putwstr_p(t_data *data);
void				ft_putstr_p(t_data *data);
void				ft_set_car(t_data *data, wchar_t c);
void				ft_putwchar_p(t_data *data, wchar_t c, int size, int n_b);
void				ft_putbin(t_data *data);
void				ft_no_types(t_data *data);
void				ft_filler(t_data *data, char opt);
void				ft_buffering(t_data *data, const void *s, int len);
void				ft_error(t_data *data, int to_remove);

# endif
