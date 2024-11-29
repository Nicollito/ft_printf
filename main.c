#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char c = 'g';
	printf("  %d\n", ft_printf("%c", c));
	printf("  %d\n", printf("%c", c));
	ft_printf("%");
	return 0;
}
