/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:25:41 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:57:09 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	int		tmp;
	int		i;
	int		mod;
	char	*str;

	tmp = nbr;
	i = 1;
	mod = nbr < 0;
	while (tmp /= 10)
		i++;
	if (!(str = malloc((i + 1 + mod) * sizeof(char))))
		return (NULL);
	if (mod)
		*str++ = '-';
	str += i;
	*str-- = '\0';
	if (nbr == 0)
		*str-- = '0';
	while (nbr)
	{
		*str-- = (nbr % 10) * (mod ? -1 : 1) + '0';
		nbr /= 10;
	}
	return (str + 1 - mod);
}
