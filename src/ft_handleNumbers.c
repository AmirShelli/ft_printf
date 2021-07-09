#include "../inc/ft_printf.h"

int	ft_handleInt(int d)
{
	return (ft_handleString(ft_itoa(d)));
}

int	ft_handleHex(int n, char x)
{
	char	hexaDeciNum[100];
	int		i;
	int		j;
	int		temp;
	int		charCount;

	i = 0;
	charCount = 0;
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hexaDeciNum[i++] = temp + 48;
		else
		{
			if (x == 'x')
				hexaDeciNum[i] = temp + 87;
			else
				hexaDeciNum[i] = temp + 55;
			i++;
		}
		n = n / 16;
	}
	j = i - 1;
	while (j >= 0)
	{	
		charCount += ft_handleCharacter(hexaDeciNum[j]);
		j--;
	}
	return (charCount);
}
