/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:05 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:54:36 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*tmp;
	t_list	*first;

	if (!f || !lst)
		return (NULL);
	tmp = f(lst);
	if (!(new_list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	first = new_list;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new_list->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (first);
}
