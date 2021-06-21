#include <stdarg.h>

/* a series of if/else that
 * takes care of knowing 
 * what percent prints what.
 * we can use vprintf 
 * for testing.
 */

int	ft_printf(char const *stringFormat, ...)
{
	int	charCount; // add charCount
	va_list	ap;

	va_start(ap, stringFormat);
	while (*stringFormat++)
	{
		charCount++;
		if (*stringFormat != '%')
			ft_putchar(*stringFormat);
		else
			// int ft_vprintf(const char *format, va_list ap)
			// use va_arg(ap, char),
			charCount += ft_vprintf(*(++stringFormat), ap);		
	}
	va_end(ap);
	return (charCount);
}