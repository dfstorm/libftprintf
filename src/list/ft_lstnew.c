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

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	
	ft_putstr("Recived by lstnew:[");
	ft_putstr(content);
	ft_putstr("]");
	new = (t_list *) malloc(sizeof(t_list *));
	if (new == NULL)
		return (NULL);
	else
	{
		if (content != NULL)
		{
			if ((new->content = (void*) ft_memalloc(content_size)) == NULL)
				return (NULL);
			ft_memcpy(&new->content, &content, content_size);
			new->content_size = content_size;
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
	}
	return (new);
}
