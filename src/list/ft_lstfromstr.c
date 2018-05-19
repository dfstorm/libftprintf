/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfromstr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:04:33 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:33:56 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfromstr(t_list **lst, char **str)
{
	int		i;
	char	*t;
	t_list	*tmp;
	char	r;

	if ((*str))
	{
		t = ft_strdup((*str));
		i = ft_strlen(t);
		while (--i >= 0)
		{
			r = t[i];
			ft_putchar(r);
			if(ft_isprintable(r))
			{
				tmp = ft_lstnew(&r, sizeof(char));
				ft_putchar((char) tmp->content);
				ft_lstadd(lst, tmp);
			}
		}
		free(t);
	}
}
