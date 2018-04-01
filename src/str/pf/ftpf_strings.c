#include "libft.h"

int		ftpf_strings_w(t_pfdata **dt, va_list *data)
{
	wchar_t	c;
	wchar_t	*s;
	int i;
	int l;
	t_list *tmp;
	
	l = 1;
	if ((*dt)->t == 'C')
	{
		c = va_arg((*data), wchar_t);
		(*dt)->data = ft_lstnew(&c, sizeof(wchar_t));
	}
	else if ((*dt)->t == 'S')
	{
		s = va_arg((*data), wchar_t *);
		l = i = ft_strlenw(s) + 1;
		while (--i >= 0)
		{
			c = s[i];
			tmp = ft_lstnew(&c, sizeof(wchar_t));
			ft_lstadd(&(*dt)->data, tmp);
		}
	}
	return (l);
}

int		ftpf_string_n(t_pfdata **dt, va_list *data)
{
	char	c;
	const char	*s;
	int l;
	
	l = 1;
	if ((*dt)->t == 'c')
	{
		c = va_arg((*data), unsigned int);
		(*dt)->data = ft_lstnew(&c, sizeof(unsigned int));
	}
	else if ((*dt)->t == 's')
	{
		s = va_arg((*data), const char *);
		ft_lstfromstr(&(*dt)->data, &s);
		l = ft_strlen(s) + 1;
	}
	return (l);
}
int		ftpf_string_p(t_pfdata **dt, va_list *data)
{
	const char	*src;
	
	if ((*dt)->t == 'p')
	{
		src = ft_luitoa_base(va_arg((*data), size_t), 16);
		ft_lstfromstr(&(*dt)->data, &src);
		ftpf_numbers_put_ox(dt, 1);
	}
	return (0);
}

void	ftpf_strings(t_pfdata **dt, va_list *data)
{
	if ((*dt)->t == 'c' ||  (*dt)->t == 's')
		ftpf_string_n(dt, data);
	else if ((*dt)->t == 'C' ||  (*dt)->t == 'S')
		ftpf_strings_w(dt, data);
	else if ((*dt)->t == 'p')
		ftpf_string_p(dt, data);
	
}
