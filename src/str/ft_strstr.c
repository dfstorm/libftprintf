/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 14:42:11 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:58:36 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_searchword(const char *str, const char *needle, int i)
{
	int	x;
	int	isok;
	int	index;

	index = 0;
	x = 0;
	isok = 1;
	while (needle[x])
	{
		if (needle[x++] != str[i + index++])
		{
			isok = 0;
			break ;
		}
	}
	return (isok ? 1 : 0);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (ft_searchword(haystack, needle, i))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
