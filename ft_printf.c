#include "ft_printf.h"
#include <stdio.h>

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

	printf("\nneeds to show the format without the %%: %s \n", format);		// don't forget. 
	return (charCount);
}

/* takes format without the %
 * manages the format
 * if given wrong format 
 * returns error.
 */

int	ft_vprintf(const char *format, va_list ap)
{
	int		charCount;
	int		spaceCount;
	char	*start;

	charCount = 0;
	start = *format;
	if (*format == '%')
	{	
		ft_putchar('%');
		charCount++;
	}
	while (ft_isdigit(*format++))
		spaceCount++;
	return (charCount);
}

char	*getFormat(const char **stringFormat)
{
	const char	*start;
	char		*tmp;
	unsigned int format_size;

	start = ++(*stringFormat);
	format_size = 1;
	if (*start == '%')
		return ("%");
	while(!ft_isalpha(**stringFormat++))
		format_size++;
	tmp = (char *) malloc(format_size + 2);
	return (ft_strcpy(tmp, start, format_size + 1));
}
