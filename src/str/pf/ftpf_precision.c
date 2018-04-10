
#include "libft.h"

void	ftpf_precision_add(t_list **lst, char c, int nb)
{
	while (nb-- > 0)
		ft_lstadd(lst, ft_lstnew(&c, sizeof(char)));
}

void	ftpf_apply_precision_insert(int i, t_pfdata **dt, int dz)
{
	int		m;
	char	c;

	if (i < 0)
		return ;
	i = (*dt)->p - i;
	m = 0;
	c = '0';
	if(dz == 0)
	{
		if(ftpf_iscinlist(&(*dt)->f, '#') && ((*dt)->t == 'o' || (*dt)->t == 'O'))
			return ;
		ft_lstwipe(&(*dt)->data);
		ftpf_precision_add(&(*dt)->data, c, (*dt)->p);
		(*dt)->w = ((*dt)->p > 0 ? (*dt)->w + (*dt)->p : (*dt)->w);
		return ;
	}
	if (!ft_isdigit(ftpf_getcfl(&(*dt)->data)))
	{
		m = ftpf_getcfl(&(*dt)->data);
		(*dt)->data = (*dt)->data->next;
	}
	ftpf_precision_add(&(*dt)->data, c, i);
	c = '-';
	if (m != 0)
		ft_lstadd(&(*dt)->data, ft_lstnew(&m, sizeof(char)));
}

void	ftpf_precision(t_pfdata **dt)
{
	t_list	*ref;
	int		i;
	int		dz;
	
	i = 0;
	ref = (*dt)->data;
	dz = 1;
	if ((*dt)->p >= 0)
	{
		if (!ftpf_istypenum((*dt)->t))
			ft_lstcutat(&(*dt)->data, (*dt)->p);
		else
		{
			dz = 0;
			while (ref)
			{
				if (ft_isdigit(ftpf_getcfl(&ref)))
				{
					dz = dz + (ftpf_getcfl(&ref) - '0');
					i++;
				}
				ref = ref->next;
			}
		}
	}
	if (ftpf_istypenum((*dt)->t))
		ftpf_apply_precision_insert(i, dt, dz);
}
