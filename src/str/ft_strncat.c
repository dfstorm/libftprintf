/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/09/21 12:16:17 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:58:12 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	index;
	size_t	from;

	from = ft_strlen(dest);
	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dest[index + from] = src[index];
		index++;
	}
	dest[index + from] = '\0';
	return (dest);
}
