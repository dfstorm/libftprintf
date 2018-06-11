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

#include "../../includes/libft.h"

void	ft_lstfromstr(t_list **lst, char **str)
{
	int		i;
	char	*relay;
	t_list	*keep;
	char	*sub;

	if ((*str))
	{
		relay = ft_strdup((*str));
		i = ft_strlen(relay);

		while (--i >= 0)
		{
			ft_putchar(relay[i]);
			if(ft_isprintable(relay[i]))
			{
				sub = ft_strnew(1);
				sub[0] = relay[i];
				keep = ft_lstnew(sub, sizeof(char) * 2);
				
				
				ft_putstr(keep->content);
				
				ft_lstadd(lst, keep);

				
			}
		}

	}
}
