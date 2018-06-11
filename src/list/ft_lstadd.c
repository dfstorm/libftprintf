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
	if(!*list)
	{
		new->next = (*list);
	}
	*list = new;
	ft_putstr("from lstadd[");
	ft_putstr((*list)->content);
	ft_putstr("]");
}
