#include "libft.h"

int		ftpf_strings_w(va_list *data, char *t, t_list **item)
{
	wchar_t	c;
	wchar_t	*s;
	int i;
	int l;
	t_list *tmp;
	
	l = 1;
	if ((*t) == 'C')
	{
		c = va_arg((*data), wchar_t);
		(*item) = ft_lstnew(&c, sizeof(wchar_t));
	}
	else if ((*t) == 'S')
	{
		s = va_arg((*data), wchar_t *);
		l = i = ft_strlenw(s) + 1;
		while (--i >= 0)
		{
			c = s[i];
			tmp = ft_lstnew(&c, sizeof(wchar_t));
			ft_lstadd(item, tmp);
		}
	}
	return (l);
}

int		ftpf_string_n(va_list *data, char *t, t_list **item)
{
	char	c;
	const char	*s;
	int i;
	int l;
	t_list *tmp;
	
	l = 1;
	if ((*t) == 'c')
	{
		c = va_arg((*data), unsigned int);
		(*item) = ft_lstnew(&c, sizeof(unsigned int));
	}
	else if ((*t) == 's')
	{
		s = va_arg((*data), const char *);
		l = i = ft_strlen(s) + 1;
		while (--i >= 0)
		{
			c = s[i];
			tmp = ft_lstnew(&c, sizeof(const char));
			ft_lstadd(item, tmp);
		}
	}
	return (l);
}

int		ftpf_strings(va_list *data, char *t, t_list **item)
{
	(*item) = ft_lstnew(NULL, 0);
	if ((*t) == 'c' ||  (*t) == 's')
		return (ftpf_string_n(data, t, item));
	else if ((*t) == 'C' ||  (*t) == 'S')
		return (ftpf_strings_w(data, t, item));
	else if ((*t) == 'p')
	{
		ft_putstr("[P Not implemeted yet.]");
	}
	return (0);
}
