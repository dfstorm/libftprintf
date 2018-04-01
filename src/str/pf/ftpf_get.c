#include "libft.h"

int		ftpf_getlength(t_pfdata **dt)
{
	int ipos;

	ipos = ft_strlen((*dt)->input) - 2;
	if((*dt)->input[ipos] == 'h')
	{
		if ((*dt)->input[--ipos] == 'h')
			return (1);
		else
			return (2);
	}
	if((*dt)->input[ipos] == 'l')
	{
		if ((*dt)->input[--ipos] == 'l')
			return (4);
		else
			return (3);
	}
	if((*dt)->input[ipos] == 'j')
		return (5);
	if((*dt)->input[ipos] == 'z')
		return (6);
	return (0);
}

char	*ftpf_get_di(t_pfdata **dt, va_list *data)
{
	int ilength;
	
	ilength = ftpf_getlength(dt);
	if (ilength == 1 || ilength == 2)
		return (ft_itoa_base(va_arg((*data), int), 10));
	if (ilength == 3)
		return (ft_itoa_base(va_arg((*data), long int), 10));
	if (ilength == 4)
		return (ft_itoa_base(va_arg((*data), long long int), 10));
	if (ilength == 5)
		return (ft_itoa_base(va_arg((*data), __intmax_t), 10));
	if (ilength == 6)
		return (ft_itoa_base(va_arg((*data), size_t), 10));
	if ((*dt)->t == 'D')
		return (ft_litoa_base(va_arg((*data), long signed int), 10));
	else
		return (ft_itoa_base(va_arg((*data), signed int), 10));
}


char	*ftpf_get_ouxx(t_pfdata **dt, va_list *data)
{
	long unsigned int	lui;
	unsigned int		ui;
	
	if ((*dt)->t == 'O' || (*dt)->t == 'U')
	{
		lui = va_arg((*data), long unsigned int);
		return (ft_luitoa_base(lui, ((*dt)->t == 'U' ? 10 : 8)));
	}
	else
	{
		ui = va_arg((*data), unsigned int);
		if ((*dt)->t == 'o')
			return (ft_uitoa_base(ui, 8));
		if ((*dt)->t == 'u')
			return (ft_uitoa_base(ui, 10));
		if ((*dt)->t == 'x')
			return (ft_uitoa_base(ui, 16));
		if ((*dt)->t == 'X')
			return (ft_strupper(ft_uitoa_base(ui, 16)));
	}
	return (NULL);
}

char	*ftpf_get(t_pfdata **dt, va_list *data)
{
	int		l;
	char	*src;
	
	
	l = ftpf_getlength(dt);
	ft_putnbr(l);
	if ((*dt)->t == 'd' || (*dt)->t == 'i' || (*dt)->t == 'D')
		src = ftpf_get_di(dt, data);
	else if(ftpf_istypenum((*dt)->t))
	{
		if(l > 0)
		{
			
		}
		else
			src = ftpf_get_ouxx(dt, data);
	}
	return (src);
}
