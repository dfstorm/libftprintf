/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftpf_write.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:10:59 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:14:09 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ftpf_write_w(int l, char c, t_pfdata **dt)
{
	if (ftpf_iscinlist(&(*dt)->f, '+') && (*dt)->wspace_char == '0')
	{
		l = l - 1;
		write(1, "+", 1);
	}
	while (l-- > 0)
		write(1, &c, 1);
}

int		w_width(t_list **flags)
{
	int	r;

	r = ftpf_iscinlist(flags, '-');
	return (r);
}

int		ftpf_write(t_pfdata **dt)
{
	int		wspace;
	int		tlen;
	t_list	*tmp_data;

	tlen = 0;
	ftpf_precision(dt);
	wspace = (*dt)->w - ft_lstcount(&(*dt)->data);
	if (!w_width(&(*dt)->f))
		ftpf_write_w(wspace, (*dt)->wspace_char, dt);
	tmp_data = (*dt)->data;
	while (tmp_data)
	{
		tlen++;
		write(1, tmp_data->content, tmp_data->content_size);
		tmp_data = tmp_data->next;
	}
	if(w_width(&(*dt)->f))
		ftpf_write_w(wspace, ' ', dt);
	tlen = tlen + (wspace > 0 ? wspace : 0);
	return (tlen);
}
