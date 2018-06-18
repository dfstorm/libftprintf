/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putlunbr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:06:16 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:06:17 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
