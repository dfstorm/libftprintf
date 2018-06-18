/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstcount.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:03:48 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:03:58 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_lstcount(t_list **d)
{
	t_list	*tmp;
	int		i;

	tmp = (*d);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	free(tmp);
	return (i);
}
