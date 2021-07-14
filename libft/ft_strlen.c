#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	if (str)
		while (str[length])
			length++;
	return (length);
}
