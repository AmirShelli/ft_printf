#include <limits.h>
#include "../inc/ft_printf.h"
int	ft_printf(const char *stringFormat, ...);

int	main(void)
{
	unsigned int	num;
	char			*str;
	int				check1;
	int				check2;

	num = 12345678;
	str = NULL;
	check1 = ft_printf("ft %d %d    %u\n", 123, -456, -num);
	check2 = printf("sd %d %d    %u\n", 123, -456, -num);
	ft_printf("----return: %d %d\n\n", check1, check2);
	check1 = ft_printf("ft %d %d   \n", INT_MAX, INT_MIN);
	check2 = printf("sd %d %d   \n", INT_MAX, INT_MIN);
	ft_printf("----return: %d %d\n\n", check1, check2);
	check1 = ft_printf("ft %i %i    %%\n", 0, 1);
	check2 = printf("sd %i %i    %%\n", 0, 1);
	ft_printf("----return: %d %d\n\n", check1, check2);
	check1 = ft_printf("ft %c %c    |%s|\n", 'a', 'c', "");
	check2 = printf("sd %c %c    |%s|\n", 'a', 'c', "");
	ft_printf("----return: %d %d\n\n", check1, check2);
	check1 = ft_printf("ft %s    %p\n", str, &str);
	check2 = printf("sd %s    %p\n", str, &str);
	ft_printf("----return: %d %d\n\n", check1, check2);
	check1 = ft_printf("ft %X %x    %p\n", 987, 654, &num);
	check2 = printf("sd %X %x    %p\n", 987, 654, &num);
	ft_printf("----return: %d %d\n\n", check1, check2);
}
