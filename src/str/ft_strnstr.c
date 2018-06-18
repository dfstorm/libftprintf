/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 10:42:55 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:58:27 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *str, char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		n = 0;
		while (to_find[n] == str[i + n] && (i + n) < len)
		{
			if (to_find[n + 1] == '\0')
				return ((char *)str + i);
			n++;
		}
		i++;
	}
	return (NULL);
}
