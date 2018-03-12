/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 11:15:50 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:56:02 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*d;
	unsigned char	o;
	int				i;

	i = 0;
	d = b;
	o = (unsigned char)c;
	while (len--)
		d[i++] = o;
	return (d);
}
