#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

char	*ft_getFormat(const char **string);
int		ft_displayFormat(char format, va_list ap);

int		ft_handleCharacter(int c);
int		ft_handleString(char *s);
int		ft_handlePointer(void *p);

int		ft_handleInt(int d);
int		ft_handleUnsInt(unsigned int d);
int		ft_handleHex(unsigned long int h, char x);
int		ft_handlePercent(void);

#endif