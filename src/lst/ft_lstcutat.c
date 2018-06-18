/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstcutat.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:04:16 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:04:25 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstcutat(t_list **lst, int count)
{
	t_list	*ref;
	int		i;
	t_list	*next;

	i = 0;
	ref = (*lst);
	while ((*lst))
	{
		i = i + 1;
		next = (*lst)->next;
		if (i == count)
		{
			(*lst)->next = NULL;
		}
		if (i > count)
		{
			free((*lst)->content);
			(*lst)->content = NULL;
			free((*lst));
			(*lst) = NULL;
		}
		(*lst) = next;
	}
	(*lst) = ref;
}
