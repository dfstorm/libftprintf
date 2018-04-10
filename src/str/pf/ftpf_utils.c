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
	char	*s;

	if (lst != NULL)
	{
		if ((*lst) != NULL)
		{
			s = (char *) (*lst)->content;
			if (s != NULL)
				if (ft_strlen(s) > 0)
					return (s[0]);
		}
	}
	return (0);
}

void	ftpf_numbers_put_ox(t_pfdata **dt, int mode)
{
	if ((*dt)->s < 0)
		return ;
	(*dt)->s = 0;
	if (ftpf_iscinlist(&(*dt)->f, '#') || (*dt)->t == 'p')
	{
		if(mode)
		{
			if ((*dt)->t == 'x' || (*dt)->t == 'p')
				ft_lstadd(&(*dt)->data, ft_lstnew("x", sizeof(char)));
			if ((*dt)->t == 'X')
				ft_lstadd(&(*dt)->data, ft_lstnew("X", sizeof(char)));
			if ((*dt)->t == 'x' || (*dt)->t == 'p' || (*dt)->t == 'X' 
				|| (*dt)->t == 'o' || (*dt)->t == 'O')
				ft_lstadd(&(*dt)->data, ft_lstnew("0", sizeof(char)));
		}
		else
		{
			
			if ((*dt)->t == 'x' || (*dt)->t == 'p' || (*dt)->t == 'X' 
				|| (*dt)->t == 'o' || (*dt)->t == 'O')
				write(1, "0", 1);
			(*dt)->s = (*dt)->s + 1;
			if ((*dt)->t == 'x' || (*dt)->t == 'p')
			{
				(*dt)->s = (*dt)->s + 1;
				write(1, "x", 1);
			}
			if ((*dt)->t == 'X')
			{
				(*dt)->s = (*dt)->s + 1;
				write(1, "X", 1);
			}
		}
	}
}

int		ftpf_islflag(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}
/*
 * dt->data = NULL;
	dt->f = NULL;
	dt->input = NULL;
	dt->wspace_char = ' ';
	dt->w = 0;
	dt->p = -1;
	dt->t = 0;
	dt->s = 0;
*/

void	ftpf_tmp_printpfdata(t_pfdata **dt)
{
	t_list	*tmp;
	
	ft_putstr("\n=== pfdata printer ===\np:");
	ft_putnbr((*dt)->p);
	ft_putstr("\nw:");
	ft_putnbr((*dt)->w);
	ft_putstr("\nt:");
	ft_putchar((*dt)->t);
	ft_putstr("\ns:");
	ft_putnbr((*dt)->s);
	ft_putstr("\nwspace_char:[");
	ft_putchar((*dt)->wspace_char);
	ft_putstr("]\nf:[");
	tmp = (*dt)->f;
	while (tmp)
	{
		write(1, tmp->content, tmp->content_size);
		ft_putchar(',');
		tmp = tmp->next;
	}
	free(tmp);
	ft_putstr("]\ndata:[");
	tmp = (*dt)->data;
	while (tmp != NULL)
	{
		write(1, tmp->content, tmp->content_size);
		ft_putchar(',');
		tmp = tmp->next;
	}
	free(tmp);
		
	
	ft_putstr("]\n======\n");
}
