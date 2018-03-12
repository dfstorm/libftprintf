/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 14:22:00 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 18:45:35 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *o;

	o = (char*)malloc(size * sizeof(char));
	if (o == NULL)
		return (NULL);
	ft_bzero(o, size);
	return (o);
}
