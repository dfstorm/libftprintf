
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
	int	r;
	
	r = ftpf_iscinlist(flags, '-');
	return (r);
}

int		ftpf_write(t_pfdata **dt)
{
	int		wspace;
	int		tlen;

	tlen = 0;
	ftpf_precision(dt);
	//ftpf_tmp_printpfdata(dt);
	wspace = (*dt)->w - ft_lstcount(&(*dt)->data);
	if (!w_width(&(*dt)->f))
		ftpf_write_w(wspace, (*dt)->wspace_char, dt);
	while ((*dt)->data)
	{
		tlen++;
		write(1, (*dt)->data->content, (*dt)->data->content_size);
		(*dt)->data = (*dt)->data->next;
	}
	if(w_width(&(*dt)->f))
		ftpf_write_w(wspace, ' ', dt);
	tlen = tlen + (wspace > 0 ? wspace : 0);
	return (tlen);
}
