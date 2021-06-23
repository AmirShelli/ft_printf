#include <stdarg.h>
#include "libft.h"

int		ft_vprintf(const char *format, va_list ap);
char	*getFormat(const char **stringFormat);

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
			// TODO fetch the format by itself
			// and process it with vprintf.
			// call it char *getFormat(char *stringFormat);
			format = getFormat(&stringFormat);
			charCount += ft_vprintf(format, ap);
		}
		stringFormat++;
	}
	va_end(ap);
	return (charCount);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int	charCount;

	charCount = 0;
	if (format[0] == '%')
	{	
		ft_putchar('%');
		charCount++;
	}
	if (format[0] == 'd')
	{	
		ft_putnbr(va_arg(ap, int));
	}
	if (format[0] == 'e')
		ft_putchar('e');
	return (charCount);
}

char	*getFormat(const char **stringFormat)
{
	const char	*arg;

	arg = ++(*stringFormat);
	if (*arg == '%')
	{
		return ("%");
	}
	// else
	printf("hello");
	return ("e");
}
