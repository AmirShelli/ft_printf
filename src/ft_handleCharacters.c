#include "../inc/ft_printf.h"

int	ft_handleString(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			write(1, &s[i++], 1);
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	return (i);
}

int	ft_handleCharacter(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_handleInt(int d)
{
	return (ft_handleString(ft_itoa(d)));
}

int	ft_handleUnsInt(unsigned int d)
{
	d = (unsigned int)(4294967295 + 1 + d);
	return (ft_handleString(ft_utoa(d)));
}

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}


