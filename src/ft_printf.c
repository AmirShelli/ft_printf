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
			ft_putstr(format);
			//charCount += ft_displayFormat(format[ft_strlen(stringFormat)], ap);
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
	if (*start == '%')
		return ("%%");
	while (!ft_isalpha(**string++))
		formatSize++;
	tmp = (char *) malloc(formatSize + 1);
	return (ft_strncpy(tmp, start, formatSize + 2));
}

// int	ft_displayFormat(char *format, va_list ap)
// {

// }
