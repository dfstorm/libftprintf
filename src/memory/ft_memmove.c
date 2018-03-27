/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 11:43:43 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:55:59 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *odst;
	char *osrc;

	odst = (char*)dst;
	osrc = (char*)src;
	if (dst > src)
		while (len--)
			odst[len] = osrc[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
