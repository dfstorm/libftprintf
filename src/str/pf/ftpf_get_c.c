#include "libft.h"

char	*ftpf_get_cw(t_pfdata **dt, va_list *data)
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

void	ftpf_get_c(t_pfdata **dt, va_list *data)
{
	int		l;
	char	*str;
	
	l = ftpf_getlength(dt);
	if (l == 3)
	{
		if ((*dt)->t == 'c')
		{
			str = ft_strnew(1);
			str[0] = va_arg((*data), signed int);
			
		}
		else if((*dt)->t == 's')
			str = va_arg((*data), char *);
	}
	return (str);
}
