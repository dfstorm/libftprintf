/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfromstr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:04:33 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 17:29:31 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfromstr(t_list **lst, char **str)
{
	int		i;
	char	*keep;
	t_list	*tmp;

	if ((*str))
	{
		keep = ft_strdup((*str));
		ft_putstr(keep);
		i = ft_strlen(keep);
		while (--i >= 0)
		{

			if(ft_isprintable(keep[i]))
			{
				ft_lstadd(lst, ft_lstnew("2", 2));
			}

		}
		//free(t);
	}

	tmp = *lst;
	while (tmp != NULL)
	{
		write(1, tmp->content, tmp->content_size);
		ft_putchar(',');
		tmp = tmp->next;
	}
}
