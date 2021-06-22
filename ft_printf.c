#include <stdarg.h>
#include "libft.h"

int	ft_vprintf(const char **format, va_list ap);

/* a series of if/else that
 * takes care of knowing 
 * what percent prints what.
 * we can use vprintf 
 * for testing.
 * 
 * printf("this is an int %d", 23);
 */

int	ft_printf(const char *stringFormat, ...)
{
	int		charCount;
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
			// int ft_vprintf(const char format, va_list ap)
			// use va_arg(ap, char)
			stringFormat++;
			charCount += ft_vprintf(&stringFormat, ap);
		}
		stringFormat++;
	}
	va_end(ap);
	return (charCount);
}

int	ft_vprintf(const char **format, va_list ap)
{
	int	charCount;

	charCount = 0;
	if (format == '%')
	{	
		ft_putchar('%');
		charCount++;
	}
	if (format == 'd')
	{
		ft_putnbr(va_arg(ap, int));
	}
	return (charCount);
}
