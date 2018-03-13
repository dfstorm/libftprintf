#include "libft.h"

void	ft_putlunbr(long unsigned int n)
{
	long unsigned int base;
	
	base = 10;
	if (n >= base)
	{
		ft_putunbr(n / base);
		ft_putchar(n % base + '0');
	}
	else
		ft_putchar(n + '0');
}
