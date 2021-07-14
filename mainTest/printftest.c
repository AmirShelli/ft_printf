#include <stdio.h>
#include "../inc/libft.h"
int	ft_printf(const char *stringFormat, ...);

int	main(void)
{
	char *p;

	p = "hello";
	ft_printf("hello\n");
	ft_printf("this is an integer %d and another one %i\n", 1, 6);
	printf("this is an integer %d and another one %i\n", 1, 6);

	ft_printf("|%25.0s|\n", "gay");
	printf("|%25.0s|\n", "gay");

	ft_printf("i: %s, d: %u\n", ft_itoa(0x12), 012);
	printf("i: %s, d: %u\n", ft_itoa(0x12), 012);

	ft_printf("this is a pointer %x\n", 8087);
	printf("this is a pointer %x\n", 8087);
}
