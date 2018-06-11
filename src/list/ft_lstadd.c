/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:00:08 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:54:17 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd(t_list **list, t_list *new)
{
	ft_putstr("recived content:{");
	ft_putstr(new->content);
	ft_putstr("}");
	if(*list != NULL)
	{
		ft_putstr("adding...");
		// here it crash on macOS. But will work on any other platform.
		new->next = (t_list *) malloc (sizeof(t_list *));
		ft_putstr("[1]");
		new->next->content = (char *) malloc (sizeof(char) * (*list)->content_size);
		ft_putstr("[2]");
		ft_memcpy(&new->next->content, &(*list)->content, (*list)->content_size);
		ft_putstr("[3]");
		new->next->content_size = (*list)->content_size;
		ft_putstr("[4]");



		// So.. Malloc problem ? next = null and of t_list type.

	}
	*list = new;
	ft_putstr("from lstadd[");
	ft_putstr((*list)->content);
	ft_putstr("]");
}
