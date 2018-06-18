/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uitoa_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:06:47 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:06:50 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	ftuibc(unsigned int i)
{
	if (i <= 9)
		return (i + '0');
	else
		return ((i - 10) + 'a');
}


char	*ft_uitoa_base(unsigned int nbr, size_t base)
{
	unsigned int	tmp;
	unsigned int	i;
	char			*str;

	tmp = nbr;
	i = 1;
	while (tmp /= base)
		i++;
	if (!(str = malloc((i + 1) * sizeof(char))))
		return (NULL);
	str += i;
	*str-- = '\0';
	if (nbr == 0)
		*str-- = '0';
	while (nbr)
	{
		*str-- = ftuibc(nbr % base);
		nbr /= base;
	}
	return (str + 1);
}

