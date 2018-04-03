
#include "libft.h"

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
	return (ftpf_iscinlist(flags, '-'));
}

int		ftpf_write(t_pfdata **dt)
{
	t_list	*tmp;
	int		precision;
	int		wspace;
	int		tlen;

	tlen = 0;
	precision = (*dt)->p;
	tmp = ((*dt)->data);
	wspace = (*dt)->w - ft_lstcount(&(*dt)->data);
	if (!w_width(&(*dt)->f))
		ftpf_write_w(wspace, (*dt)->wspace_char, dt);
	while (tmp && (!precision || (precision && --(*dt)->p >= 0)))
	{
		tlen++;
		write(1, tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	if(w_width(&(*dt)->f))
		ftpf_write_w(wspace, ' ', dt);
	tlen = tlen + (wspace > 0 ? wspace : 0);
	free(tmp);
	return (tlen);
}
