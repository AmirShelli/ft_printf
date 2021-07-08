#include "../inc/ft_printf.h"

int	ft_handleInt(int d)
{
	return (ft_handleString(ft_itoa(d)));
}

int	ft_handleHex(int n)
{
	char	hexaDeciNum[100];
	int		i;
	int		temp;
	int		charCount;

	i = 0;
	charCount = 0;
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
		{
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexaDeciNum[i] = temp + 55;
			i++;
		}
		n = n / 16;
	}
	for (int j = i - 1; j >= 0; j--)
		charCount += ft_handleCharacter(hexaDeciNum[j]);
	return (charCount);
}
