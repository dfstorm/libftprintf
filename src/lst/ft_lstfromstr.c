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

void	ft_lstfromstr(t_list **ref_pt_list, char **ref_str)
{
	int		i;
	t_list	*pt_keep;
	char	*substr;
	char	sub;

	if ((*ref_str))
	{
		substr = ft_strdup((*ref_str));
		i = ft_strlen(substr);
		while (--i >= 0)
		{
			if(ft_isprintable(substr[i]))
			{
				sub = substr[i];
				pt_keep = ft_lstnew(&sub, sizeof(char));
				ft_lstadd(ref_pt_list, pt_keep);
			}
		}
		free(substr);
	}
}
