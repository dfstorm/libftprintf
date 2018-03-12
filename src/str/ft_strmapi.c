/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 17:39:21 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:58:09 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (s)
	{
		i = -1;
		if (!(str = ft_strdup(s)) || !s)
			return (NULL);
		while (s[++i] != '\0')
			str[i] = f(i, s[i]);
		return (str);
	}
	return (NULL);
}
