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
	t_list	*keep;
	t_list	*keepa;
	char	*substr;
	char	sub;
	char * testingc;

	if ((*str))
	{
		substr = ft_strdup((*str));
		i = ft_strlen(substr);
		while (--i >= 0)
		{
			if(ft_isprintable(substr[i]))
			{
				sub = substr[i];
				keep = (t_list *) malloc(sizeof(t_list *));
				keepa = ft_lstnew_o(&keep, &sub, sizeof(char));

				ft_putstr("write:[");
				write(1, keepa->content, keepa->content_size);
				ft_putstr("]");

				testingc  = (char*) keepa->content;
				ft_putstr(">[");
				ft_putstr(testingc);
				ft_putstr("]<");


				ft_lstadd(lst, keepa);
			}
		}
	}
}
