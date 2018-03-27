#include "libft.h"

void	ftpf_core(const char **str, va_list *data, int *size)
{
	int		i;
	char	*src;
	//char	*tmp;
	i = -1;

	//tmp = NULL;
	src = NULL;
	if((*size) || data) {}
	
	while ((*str)[++i] != '\0')
	{
		if((*str)[i] == '%')
		{
			src = ftpf_isolate(str, &i);
			ftpf_types(&src, data, size);
			//ft_putstr("{");
			//ft_putstr(src);
			//ft_putchar('}');
			free(src);
		}
		else
		{
			(*size)++;
			ft_putchar((*str)[i]);
		}
	}
	
}
 
