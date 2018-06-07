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

	if ((*str))
	{
		relay = ft_strdup((*str));
		i = ft_strlen(relay);

		while (--i >= 0)
		{

			if(ft_isprintable(relay[i]))
			{
				keep = ft_lstnew(&relay[i], sizeof(char));
				ft_lstadd(lst, keep);
			}
		}
		free(relay);
	}
}
