// TODO: Warning: inclomplete
#include "libft.h"

void	ft_addnb(t_list **lst, int nb)
{
	char c;

	if (nb == -2147483648)
	{
		//ft_putstr("-2147483648");
	}
	
	if (nb < 0)
	{
		c = '-';
		ft_lstadd(item, ft_lstnew(&c, sizeof(char)));
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		
		nb = nb / 10;
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
