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
			charCount += ft_displayFormat(format[ft_strlen(stringFormat)], ap);
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

/*
 * Has to be changed with bonuses in mind.
 * Not compatible with the bonus part at all.
 */

int	ft_displayFormat(char format, va_list ap)
{
	if (format == 'd')
}
