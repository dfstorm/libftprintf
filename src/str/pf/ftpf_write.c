
#include "libft.h"

void	ftpf_write_w(int l, char c)
{
	while (l-- > 0)
		write(1, &c, 1);
}

int		w_width(t_list **flags)
{
	t_list	*tmp;
	char	*str;

	tmp = (*flags);
	while (tmp)
	{
		
		str = (char *) tmp->content;
		ft_putstr(str);
		if (ft_strlen(str) > 0)
			if(str[0] == '-')
				return (1);
		
		tmp = tmp->next;
	}
	return (0);
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
	
	
	wspace = (*dt)->w - ft_lstcount(&(*dt)->data) + 1;
	
	
	
	if (!w_width(&(*dt)->f))
		ftpf_write_w(wspace, ' ');
	while (tmp && (!precision || (precision && --(*dt)->p >= 0)))
	{
		tlen++;
		write(1, tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	if(w_width(&(*dt)->f))
		ftpf_write_w(wspace, ' ');
	tlen = tlen + wspace;
	free(tmp);
	return (tlen);
}
