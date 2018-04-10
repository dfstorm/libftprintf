#include "libft.h"

void	ftpf_core(const char **str, va_list *data, int *size)
{
	int		i;
	char	*src;
	
	i = -1;
	src = NULL;
	while ((*str)[++i] != '\0')
	{
		if((*str)[i] == '%')
		{
			src = ftpf_isolate(str, &i, size);
			if (src)
				ftpf_types(&src, data, size);
			free(src);
		}
		else
		{
			(*size) = (*size) + 1;
			ft_putchar((*str)[i]);
		}
	}
	
}
 
