#include "libft.h"

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	int		istatus;
	
	istatus = 0;
	va_start(arg, str);
	ftpf_core(&str, &arg, &istatus);
	va_end(arg);
	return (istatus);
/*
	int		i = -1;
	int		e;
	e = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if ( i > 0 && str[i - 1] == '%' && str[i] == '%')
				ft_putchar('%');
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(arg, signed int));
			else if (str[i] == 's')
		*		ft_putstr(va_arg(arg, const char *));
			else if (str[i] == 'c')
		*		ft_putchar(va_arg(arg, unsigned int));
			else if (str[i] == 'o')
				ft_putstr(ft_itoa_base(va_arg(arg, unsigned int), 8));
			else if (str[i] == 'S')
				ft_putlstr(va_arg(arg, wchar_t*));
			else if (str[i] == 'u')
				ft_putunbr(va_arg(arg, unsigned int));
			else if (str[i] == 'x')
				ft_putstr(ft_itoa_base(va_arg(arg, unsigned int), 16));
			else if (str[i] == 'X')
				ft_putstr(ft_strupper(ft_itoa_base(va_arg(arg, unsigned int), 16)));
			else if (str[i] == 'p')
			{
				ft_putstr("0x");
				ft_putstr(ft_uitoa_base(va_arg(arg, size_t), 16));
			}
			else if (str[i] == 'O')
				ft_putstr(ft_uitoa_base(va_arg(arg, size_t), 8));
			else if (str[i] == 'U')
				ft_putlunbr(va_arg(arg, long unsigned int));
			else if (str[i] == 'D')
				ft_putlsnbr(va_arg(arg, long signed int));
			else if (str[i] == 'C')
				ft_putlchar(va_arg(arg, wchar_t));
			else
			{
				e = str[i];
				break ;
			}
			i++;
		}
		ft_putchar(str[i]);
	}
	va_end(arg);
	if (e >= 0)
		show_usage(e);
	return (0);
*/
}
