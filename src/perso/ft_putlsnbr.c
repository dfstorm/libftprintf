#include "libft.h"

void	ft_putlsnbr(long signed int n)
{
	long signed int base;
	
	base = 10;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= base)
	{
		ft_putnbr(n / base);
		ft_putchar(n % base + '0');
	}
	else
		ft_putchar(n + '0');
}
