#include "../inc/ft_printf.h"
#include "../inc/libft.h"

static void	ft_puthex(unsigned long int n, char x)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, x);
		ft_puthex(n % 16, x);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{	
			if (x == 'x')
				ft_putchar(n - 10 + 'a');
			else
				ft_putchar(n - 10 + 'A');
		}
	}
}

static int	ft_xlen(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_handleHex(unsigned long int n, char x)
{
	ft_puthex(n, x);
	return (ft_xlen(n));
}

int	ft_handlePointer(void *p)
{
	ft_putstr("0x");
	ft_puthex((unsigned long) p, 'x');
	return (ft_xlen((unsigned long)p) + 2);
}
