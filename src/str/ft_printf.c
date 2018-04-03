#include "libft.h"

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	int		size;
	
	size = 0;
	va_start(arg, str);
	ftpf_core(&str, &arg, &size);
	va_end(arg);
	return (size);
}
