#include "libft.h"

int		ftpf_numbers(va_list *data, char *t, t_list **item)
{
	const char	*src;
	
	if ((*t) == 'd' || (*t) == 'i')
		src =  ft_itoa_base(va_arg((*data), signed int), 10);
	if ((*t) == 'u')
		src = ft_uitoa_base(va_arg((*data), unsigned int), 10);
	if ((*t) == 'U')
		src = ft_luitoa_base(va_arg((*data), long unsigned int), 10);
	if ((*t) == 'D')
		src = ft_litoa_base(va_arg((*data), long signed int), 10);
	if ((*t) == 'o')
		src =  ft_itoa_base(va_arg((*data), signed int), 8);
	if ((*t) == 'O')
		src = ft_uitoa_base(va_arg((*data), unsigned int), 8);
	if ((*t) == 'x')
		src =  ft_uitoa_base(va_arg((*data), unsigned int), 16);
	if ((*t) == 'X')
		src = ft_strupper(ft_uitoa_base(va_arg((*data), unsigned int), 16));
	ft_lstfromstr(item, &src);
	return (0);
}
