/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:04:53 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:57:13 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int index;
	int from;

	from = ft_strlen(dest);
	index = 0;
	while (src[index] != '\0')
	{
		dest[index + from] = src[index];
		index++;
	}
	dest[index + from] = '\0';
	return (dest);
}
