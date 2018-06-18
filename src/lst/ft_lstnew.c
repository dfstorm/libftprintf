/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:01:09 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 17:37:47 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void const *pt_content, size_t i_content_size)
{
	t_list	*pt_list;

	pt_list = (t_list *) malloc(sizeof(t_list));
	if (pt_list == NULL || pt_list == 0 || pt_content == NULL)
		return (NULL);
	else
	{
     	pt_list->content = malloc(i_content_size);
		if (pt_list->content == NULL || pt_list->content == 0)
			return (NULL);
		ft_memcpy(pt_list->content, pt_content, i_content_size);
		pt_list->content_size = i_content_size;
		pt_list->next = NULL;
	}
	return (pt_list);
}
