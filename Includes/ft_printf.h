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

# endif
