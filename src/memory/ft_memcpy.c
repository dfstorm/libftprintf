/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 11:35:34 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:55:52 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *odst;
	char *osrc;
	size_t	nb;

	nb = -1;
	odst = (char*) dst;
	osrc = (char*) src;

	ft_putchar(*osrc);

	while (++nb < n)
		odst[nb] = *osrc;
	return (dst);
}
