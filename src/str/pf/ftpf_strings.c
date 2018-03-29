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
	int l;
	
	l = 1;
	if ((*t) == 'c')
	{
		c = va_arg((*data), unsigned int);
		(*item) = ft_lstnew(&c, sizeof(unsigned int));
	}
	else if ((*t) == 's')
	{
		s = va_arg((*data), const char *);
		ft_lstfromstr(item, &s);
		l = ft_strlen(s) + 1;
	}
	return (l);
}
int		ftpf_string_p(va_list *data, char *t, t_list **item)
{
	const char	*src;
	
	if ((*t) == 'p')
	{
		src = ft_luitoa_base(va_arg((*data), size_t), 16);
		ft_lstfromstr(item, &src);
	}
	return (0);
}

int		ftpf_strings(va_list *data, char *t, t_list **item)
{
	if ((*t) == 'c' ||  (*t) == 's')
		return (ftpf_string_n(data, t, item));
	else if ((*t) == 'C' ||  (*t) == 'S')
		return (ftpf_strings_w(data, t, item));
	else if ((*t) == 'p')
		return (ftpf_string_p(data, t, item));
	return (0);
}
