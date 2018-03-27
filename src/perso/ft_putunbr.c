#include "libft.h"

void	ft_putunbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
