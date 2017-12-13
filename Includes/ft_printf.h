/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:53:27 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/13 20:56:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**							*** LIBRAIRIES ***
*/

# include "../libft/Includes/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
**							*** STRUCTURES ***
*/

typedef struct	s_data
{
	int			i;
	int			fd;
	int			len;
	int			i_form;
	char		*s;
	char		*form;
	va_list		ap;

}				t_data;

/*
**							*** PROTOTYPES ***
*/

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
void			ft_attribuate(t_data *data);
void			ft_put_type(t_data *data);
void			ft_putstr_printf(t_data *data);

# endif
