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
	if(*list == NULL)
	{
		*list = new;
	}
	else
	{
		new->next = *list;
		*list = new;
	}
}
