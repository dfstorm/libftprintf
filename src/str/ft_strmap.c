/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 16:36:44 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:58:06 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (!(str = ft_strdup(s)) || !s)
			return (NULL);
		while (str[i])
		{
			str[i] = f(str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
