/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/14 09:38:35 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 22:42:58 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l;

	if (s1 && s2)
	{
		l = ft_strlen(s1) + ft_strlen(s2) + 1;
		str = (char*)malloc(l * sizeof(char));
		if (!str)
			return (NULL);
		l = 0;
		while (*(s1) != '\0')
			str[l++] = *(s1++);
		while (*(s2) != '\0')
			str[l++] = *(s2++);
		str[l] = '\0';
		return (str);
	}
	return (NULL);
}
