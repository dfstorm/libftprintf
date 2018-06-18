/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 16:18:02 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:27:54 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	size++;
	str = (char*)malloc(size * sizeof(char));
	if (str)
	{
		ft_bzero(str, size);
		return (str);
	}
	else
		return (NULL);
}
