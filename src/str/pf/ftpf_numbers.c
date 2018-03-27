#include "libft.h"

/*
d	Signed decimal integer						
i	Signed decimal integer						
u	Unsigned decimal integer				
*/
int		ftpf_numbers_diu(va_list *data, char *t, t_list **item)
{
	signed int		d;
	unsigned int	u;
	signed int		itmp;
	int				len;
	if ((*t) == 'd' || (*t) == 'i')
	{
		d = va_arg((*data), signed int);
		if(d < 0)
		{
			
			itmp = (d % 10) + '0';
			
			
		}
		
		
		
		while (d >= 10)
		{
			itmp = (d % 10) + '0';
			ft_lstadd(item, ft_lstnew(&itmp, sizeof(signed int)));
			d = d / 10;
			len++;
		}
		itmp = d + '0';
		len++;
		ft_lstadd(item, ft_lstnew(&itmp, sizeof(signed int)));
	}
	if ((*t) == 'd' || (*t) == 'i')
	{
		u = va_arg((*data), unsigned int);
		while (u >= 10)
		{
			itmp = (u % 10) + '0';
			ft_lstadd(item, ft_lstnew(&itmp, sizeof(signed int)));
			u = u / 10;
			len++;
		}
		itmp = u + '0';
		len++;
		ft_lstadd(item, ft_lstnew(&itmp, sizeof(signed int)));
	}
	return (len);
}

/*
U   [lu]	Long Unsigned decimal integer		
D	[ld]	Long Signed decimal integer		
*/
int		ftpf_numbers_ud(va_list *data, char *t, t_list **item)
{
	if (data || t || item) {}
	return (0);
}

/*
o	Unsigned octal								
O	[lo]	Long Unsigned octal					
*/
int		ftpf_numbers_oo(va_list *data, char *t, t_list **item)
{
	if (data || t || item) {}
	return (0);
}
/*
x	Unsigned hexadecimal integer				
X	Unsigned hexadecimal integer (uppercase)	
*/
int		ftpf_numbers_xx(va_list *data, char *t, t_list **item)
{
	if (data || t || item) {}
	return (0);
}


int		ftpf_numbers(va_list *data, char *t, t_list **item)
{
	if ((*t) == 'd' || (*t) == 'i' || (*t) == 'u')
		return ftpf_numbers_diu(data, t, item);
	if ((*t) == 'U' || (*t) == 'D')
		return ftpf_numbers_ud(data, t, item);
	if ((*t) == 'o' || (*t) == 'O')
		return ftpf_numbers_oo(data, t, item);
	if ((*t) == 'x' || (*t) == 'X')
		return ftpf_numbers_xx(data, t, item);
	return (0);
}
