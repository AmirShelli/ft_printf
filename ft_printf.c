#include <stdarg.h>

int ft_vprintf(const char format, va_list ap);

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

	va_start(ap, stringFormat);
	while (*stringFormat++)
	{
		charCount++;
		if (*stringFormat != '%')
			ft_putchar(*stringFormat);
		else
			charCount += vprintf(*(++stringFormat), ap);
			// int ft_vprintf(const char format, va_list ap)
			// use va_arg(ap, char)
	}
	va_end(ap);
	return (charCount);
}

int ft_vprintf(const char format, va_list ap)
{
	int	charCount;

	if (format == '%')
	{	
		ft_putchar('%');
		charCount++;
	}
	if (format == 'd')
	{
		putnum(va_arg(ap, int));
	}
}