#include "../inc/ft_printf.h"
static int	ft_displayString(char *s)
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
	free(s);
	return (i);
}

int	ft_handleString(char *s)
{
	char	*string;

	string = ft_strdup(s);
	return (ft_displayString(string));
}

int	ft_handleInt(int d)
{
	return (ft_displayString(ft_itoa(d)));
}

int	ft_handleUnsInt(unsigned int d)
{
	d = (unsigned int)(4294967295 + 1 + d);
	return (ft_displayString(ft_utoa(d)));
}
