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
	void	*testing;
	char	*testingc;

	new = (t_list *) malloc(sizeof(t_list *));

	if (new == NULL)
		return (NULL);
	else
	{
		new->content = NULL;
		new->content_size = 0;
		if (content != NULL)
		{
			new->content = malloc(
				sizeof(void) * (content_size + 1));
			if (new->content == NULL)
				return (NULL);
			testing = ft_memcpy_ref(&new->content, &content, content_size);
			testingc = (char*) testing;
			ft_putstr(">>");
			ft_putstr(testingc);
			ft_putstr("<<");

			new->content_size = content_size;
		}
		new->next = NULL;
	}
	return (new);
}
