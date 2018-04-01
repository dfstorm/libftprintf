#include "libft.h"

int		ftpf_istypenum(char c)
{
	const char	num[10] = "diouxXOUD";
	int			i;
	
	i = -1;
	while (num[++i])
		if (c == num[i])
			return (1);
	return (0);
}

int		ftpf_iscinlist(t_list **list, char c)
{
	t_list	*tmp;
	char	*str;

	tmp = (*list);
	while (tmp)
	{
		str = (char *) tmp->content;
		if (ft_strlen(str) > 0)
			if(str[0] == c)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	ftpf_getcfl(t_list **lst)
{
	char *s;
	
	s = (char *) (*lst)->content;
	if (ft_strlen(s) > 0)
		return (s[0]);
	else
		return (0);
	
}

void	ftpf_numbers_put_ox(t_pfdata **dt, int mode)
{
	if (ftpf_iscinlist(&(*dt)->f, '#') || (*dt)->t == 'p')
	{
		if(mode)
		{
			if ((*dt)->t == 'x' || (*dt)->t == 'p')
				ft_lstadd(&(*dt)->data, ft_lstnew("x", sizeof(char)));
			if ((*dt)->t == 'X')
				ft_lstadd(&(*dt)->data, ft_lstnew("X", sizeof(char)));
			ft_lstadd(&(*dt)->data, ft_lstnew("0", sizeof(char)));
		}
		else
		{
			write(1, "0", 1);
			if ((*dt)->t == 'x' || (*dt)->t == 'p')
				write(1, "x", 1);
			if ((*dt)->t == 'X')
				write(1, "X", 1);
		}
	}
}

int		ftpf_islflag(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}
