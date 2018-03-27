/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 10:57:41 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 18:37:32 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*strout;
	int		i;

	i = 0;
	strout = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (strout == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		strout[i] = s[i];
		i++;
	}
	strout[i] = '\0';
	return (strout);
}
