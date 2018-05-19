/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putlsnbr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:06:01 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:06:03 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
