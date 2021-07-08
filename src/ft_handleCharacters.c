#include "../inc/ft_printf.h"

int	ft_handleString(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			write(1, &s[i++], 1);
	return (i);
}

int	ft_handleCharacter(int c)
{
	write(1, c, 1);
	return (1);
}
