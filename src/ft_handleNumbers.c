#include "../inc/ft_printf.h"

int	ft_handleInt(int d)
{
	char	*itoa;

	return (ft_handleString(ft_itoa(d)));
}

int	ft_handleInteger(int i)
{
	char	*itoa;

	return (ft_handleString(ft_itoa(i)));
}
