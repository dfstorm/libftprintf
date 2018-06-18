/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/09/21 11:42:55 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:58:15 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	if (*s1 == '\0' || *s2 == '\0')
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	i = -1;
	while (++i < n && *s1++ == *s2++ && !(*s1 == '\0' && *s2 == '\0'))
		;
	return (*((unsigned char *)s1 - 1) - *((unsigned char *)s2 - 1));
}
