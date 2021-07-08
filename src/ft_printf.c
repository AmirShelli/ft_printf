#include "../inc/ft_printf.h"

int	ft_printf(const char *stringFormat, ...)
{
	int		charCount;
	char	*format;
	va_list	ap;

	charCount = 0;
	va_start(ap, stringFormat);
	while (*stringFormat)
	{
		charCount++;
		if (*stringFormat != '%')
			ft_putchar(*stringFormat);
		else
		{
			format = ft_getFormat(&stringFormat);
			charCount += ft_displayFormat(format[ft_strlen(format) - 1], ap);
		}
		stringFormat++;
	}
	va_end(ap);
	return (charCount);
}

char	*ft_getFormat(const char **string)
{
	char			*start;
	char			*tmp;
	unsigned int	formatSize;

	start = (char *)(++(*string));
	formatSize = 1;
	while (!ft_isalpha(**string) && **string != '%')
	{	
		formatSize++;
		(*string)++;
	}
	tmp = (char *) malloc(formatSize + 1);
	return (ft_strncpy(tmp, start, formatSize));
}

/* for self:
 * Has to be changed with bonuses in mind.
 * Not compatible with optional flags at all.
 * It shouldn't accept a char as format 
 * if bonuses are to be added.
 * 
 * TODO: try to map 2 arrays together
 * one with the formats the second 
 * with needed functions. Loop through it
 * to apply what's needed.
 */

int	ft_displayFormat(char format, va_list ap)
{
	if (format == 'c')
		return (ft_handleCharacter(va_arg(ap, int)));
	if (format == 's')
		return (ft_handleString(va_arg(ap, void *)));
	if (format == 'p')
		return (ft_handlePointer(va_arg(ap, void *)));
	if (format == 'i' || format == 'd' || format == 'u')
		return (ft_handleInt(va_arg(ap, int)));
	// if (format == 'u')
	// 	return (ft_handleUnsigned(va_arg(ap, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_handleHex(va_arg(ap, int)));
	if (format == '%')
		return (ft_handlePercent());
	return (-1);
}
