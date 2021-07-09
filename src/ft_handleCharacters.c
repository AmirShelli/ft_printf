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
	write(1, &c, 1);
	return (1);
}

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

int	ft_handlePointer(void *p0)
{
	int			i;
	uintptr_t	p;
	int			check;
	int			charCount;

	p = (uintptr_t)p0;
	ft_putchar('0');
	ft_putchar('x');
	check = 0;
	charCount = 0;
	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{

		if ((int)((p >> i) & 0xf) != 0)
			check = 1;
		if (check)
		{	
			ft_putchar(hex_digit((p >> i) & 0xf));
			charCount++;
		}
		i -= 4;
	}
	return (charCount);
}
