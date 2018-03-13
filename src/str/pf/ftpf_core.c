#include "libft.h"

void	ftpf_entry(const char **str, va_list *data, int *ipos)
{
	char *query;
	if (data) {}
	query = ftpf_extract(str, ipos);
	ft_putstr("-1-");
	ft_putstr(query);
	ft_putstr("-2-");
}

void	ftpf_core(const char **str, va_list *data)
{
	int i;
	
	i = -1;
	while ((*str)[++i] != '\0')
	{
		if((*str)[i] == '%')
			ftpf_entry(str, data, &i);
		else
			ft_putchar((*str)[i]);
	}
}
 
