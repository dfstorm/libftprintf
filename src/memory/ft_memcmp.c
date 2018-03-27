/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 14:11:41 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:55:49 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *os1;
	unsigned const char *os2;
	size_t				i;

	i = 0;
	os1 = s1;
	os2 = s2;
	while (i < n)
	{
		if (os1[i] != os2[i])
			return (os1[i] - os2[i]);
		i++;
	}
	return (0);
}
