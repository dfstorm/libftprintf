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

				pt_keep = (t_list *) malloc(sizeof(t_list));

				ft_lstnew_o(&pt_keep, &sub, sizeof(char));

        //ft_lstnew_o((t_list *) keep, &sub, sizeof(char));
				ft_putstr("write:[");
				write(1, pt_keep->content, pt_keep->content_size);
				ft_putstr("]");


        ft_putstr("Predata:");
        if (*ref_pt_list != NULL)
          write (1, (*ref_pt_list)->content, (*ref_pt_list)->content_size);
        ft_putstr("\n======\n");
				ft_lstadd(ref_pt_list, pt_keep);
        ft_putstr("Postdata:");
        if (*ref_pt_list != NULL)
          write (1, (*ref_pt_list)->content, (*ref_pt_list)->content_size);
        ft_putstr("<<<\n");
			}
		}
	}
}
