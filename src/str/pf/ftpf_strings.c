#include "libft.h"

int		ftpf_strings_w(t_pfdata **dt, va_list *data)
{
	wchar_t	c;
	wchar_t	*s;
	int i;
	int l;

	l = 1;
	if ((*dt)->t == 'C' || (*dt)->t == 'c')
	{
		c = va_arg((*data), wchar_t);
		(*dt)->data = ft_lstnew(&c, sizeof(wchar_t));
	}
	else if ((*dt)->t == 'S' || (*dt)->t == 's')
	{
		s = va_arg((*data), wchar_t *);
		l = i = ft_strlenw(s);
		while (--i >= 0)
			ft_lstadd(&(*dt)->data, ft_lstnew(&s[i], sizeof(char)));
		free(s);
	}
	return (l);
}

int		ftpf_string_n(t_pfdata **dt, va_list *data)
{
	char	c;
	//char	*s;
	int		l;
	char	*tmp;
	l = 1;
	if ((*dt)->t == 'c')
	{
		c = va_arg((*data), unsigned int);
		(*dt)->data = ft_lstnew(&c, sizeof(unsigned int));
	}
	else if ((*dt)->t == 's')
	{
		tmp = ft_strdup(va_arg((*data), char *));
		ft_lstfromstr(&(*dt)->data, &tmp);
		l = ft_strlen(tmp);
		free(tmp);
	}
	return (l);
}
int		ftpf_string_p(t_pfdata **dt, va_list *data)
{
	char	*src;
	
	if ((*dt)->t == 'p')
	{
		src = ft_luitoa_base(va_arg((*data), size_t), 16);
		ft_lstfromstr(&(*dt)->data, &src);
		ftpf_numbers_put_ox(dt, 1);
		free(src);
	}
	return (0);
}

void	ftpf_strings(t_pfdata **dt, va_list *data)
{
	int	l;
	
	l = ftpf_getlength(dt);
	if (l == 3 || (*dt)->t == 'C' ||  (*dt)->t == 'S')
		ftpf_strings_w(dt, data);
	else if ((*dt)->t == 'c' ||  (*dt)->t == 's')
		ftpf_string_n(dt, data);		
	else if ((*dt)->t == 'p')
		ftpf_string_p(dt, data);
}
