
#include "libft.h"

void	ftpf_write_w(int l, char c)
{
	while (l-- > 0)
		write(1, &c, 1);
}

int		is_minus_f(t_list **flags)
{
	t_list	*tmp;
	char	*st;
	int		m;
	
	m = 0;
	tmp = (*flags);
	while (tmp)
	{
		st = (char *) tmp->content;
		if (ft_strlen(st) > 0)
			if (st[0] == '-')
				m = 1;
		tmp = tmp->next;
	}
	free(tmp);
	return (m);
}

int		ftpf_write(t_list **data, int p, int w, t_list **f)
{
	t_list	*tmp;
	int		i;
	int		m;
	int		tlen;

	tlen = 0;
	i = p;
	tmp = (*data);
	
	m = w - ((ft_lstcount(data) > i ? i : ft_lstcount(data)));
	if (p == 0)
		m = w - ft_lstcount(data);
	if (!is_minus_f(f))
		ftpf_write_w(m, ' ');
	while (tmp && (!i || (i && --p >= 0)))
	{
		tlen++;
		write(1, tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	if(is_minus_f(f))
		ftpf_write_w(m, ' ');
	tlen = tlen + m;
	free(tmp);
	return (tlen);
}
