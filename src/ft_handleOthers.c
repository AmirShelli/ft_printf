#include "../inc/ft_printf.h"

int	ft_handlePercent(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_handleCharacter(int c)
{
	write(1, &c, 1);
	return (1);
}
