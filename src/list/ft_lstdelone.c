/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdelone.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:00:53 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:54:28 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **list, void (*del)(void*, size_t))
{
	if (*list)
		(*del)((*list)->content, (*list)->content_size);
	ft_memdel((void **)list);
}
