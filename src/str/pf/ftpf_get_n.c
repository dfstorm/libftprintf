#include "libft.h"

int		ftpf_getlength(t_pfdata **dt)
{
	int ipos;

	ipos = ft_strlen((*dt)->input) - 2;
	if (ipos < 0)
		return (0);
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

char	*ftpf_get_numuwf(va_list *data, int l, int base, t_pfdata **dt)
{
	char	*str;
	
	if (l == 1)
		str = ft_uitoa_base((unsigned char) va_arg((*data), unsigned int), base);
	else if (l == 2)
		str = ft_uitoa_base((unsigned short int) va_arg((*data), unsigned int), base);
	else if (l == 3)
		str = ft_luitoa_base((unsigned long int) va_arg((*data), unsigned long int), base);
	else if (l == 4 || l == 5 || l == 6)
		str = ft_lluitoa_base((unsigned long long int) va_arg((*data), unsigned long long int), base);
	else
		str = ft_uitoa_base((unsigned int) va_arg((*data), unsigned int), base);
	if (ft_strlen(str) == 1 && str[0] == '0')
		(*dt)->s = -1;
	return (str);
}

char	*ftpf_get_numswf(va_list *data, int l, int base, t_pfdata **dt)
{
	char	*str;

	if (l == 1)
		str = ft_itoa_base((signed char) va_arg((*data), int), base);
	else if (l == 2)
		str = ft_itoa_base((short int) va_arg((*data), int), base);
	else if (l == 3)
		str = ft_litoa_base((long int) va_arg((*data), long int), base);
	else if (l == 4 || l == 5 || l == 6)
		str = ft_llitoa_base((long long int) va_arg((*data), long long int), base);
	else
		str = ft_itoa_base((int) va_arg((*data), int), base);
	if (ft_strlen(str) == 1 && str[0] == '0')
		(*dt)->s = -1;
	return (str);
}

char	*ftpf_get_n(t_pfdata **dt, va_list *data)
{
	int		l;
	char	*src;
	int		base;
	char	*out;

	base = 10;
	l = ftpf_getlength(dt);
	if(ftpf_istypenum((*dt)->t))
	{
		if((*dt)->t == 'o' || (*dt)->t == 'O')
			base = 8;
		if((*dt)->t == 'x' || (*dt)->t == 'X')
			base = 16;
		if((*dt)->t == 'D' || (*dt)->t == 'U' || (*dt)->t == 'O')
			l = 3;
		if((*dt)->t == 'D' || (*dt)->t == 'd' || (*dt)->t == 'i')
			src = ftpf_get_numswf(data, l, base, dt);
		else
			src = ftpf_get_numuwf(data, l, base, dt);
	}
	
	if ((*dt)->t == 'X')
		src = ft_strupper(src);
	out = ft_strdup(src);
	free(src);
	return (out);
}
