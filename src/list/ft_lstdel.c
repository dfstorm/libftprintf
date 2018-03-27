/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:00:14 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:54:24 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **list, void (*del)(void *, size_t))
{
	t_list	*erase;
	t_list	*next;

	erase = *list;
	while (erase)
	{
		next = erase->next;
		del(erase->content, erase->content_size);
		free(erase);
		erase = next;
	}
	*list = NULL;
}
