/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 10:05:45 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:58:30 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *ipos;
	const char *p;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	ipos = NULL;
	while ((p = ft_strchr(s, c)) != NULL)
	{
		ipos = p;
		s = p + 1;
	}
	return ((char*)ipos);
}
