#include "libft.h"

int		ftpf_nis(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (1);
	return (0);
}

void	ftpf_numbers_put_sign(t_pfdata **dt)
{
	char	*tmp;

	if (ftpf_iscinlist(&(*dt)->f, '0'))
		return ;
	ftpf_numbers_put_ox(dt, 1);
	if(ftpf_nis((*dt)->t) == 0)
		return ;
	if (ftpf_iscinlist(&(*dt)->f, '+') || ftpf_iscinlist(&(*dt)->f, ' '))
	{
		if(ftpf_getcfl(&(*dt)->data) != '-')
		{
			tmp = ft_strnew(1);
			if(ftpf_iscinlist(&(*dt)->f, '+'))
				tmp[0] = '+';
			else
				tmp[0] = '-';
			ft_lstadd(&(*dt)->data, ft_lstnew(tmp, sizeof(char)));
			free(tmp);
		}
		
	}
}

void	ftpf_numbers_put_lefpad(t_pfdata **dt)
{
	int		ilen;
	char 	c;

	c = ftpf_getcfl(&(*dt)->data);
	if ((*dt)->w == 0)
		return ;
	if (ftpf_iscinlist(&(*dt)->f, '0') && !ftpf_iscinlist(&(*dt)->f, '-'))
	{
		ilen = (*dt)->w - ft_lstcount(&(*dt)->data) - ftpf_nis((*dt)->t);
		if (ftpf_iscinlist(&(*dt)->f, '#'))
			if ((*dt)->t == 'o' || (*dt)->t == 'O' || (*dt)->t == 'x'||
				(*dt)->t == 'X')
				ilen = ilen - 2;
		if (ftpf_nis((*dt)->t) == 1)
		{
			if (c == '-')
			{
				write(1, "-", 1);
				(*dt)->data->content = "0";
			} else {
				if (ftpf_iscinlist(&(*dt)->f, '+'))
					write(1, "+", 1);
				else if (ftpf_iscinlist(&(*dt)->f, ' '))
					write(1, " ", 1);
				else
					write(1, "0", 1);
			}
		}
		ftpf_numbers_put_ox(dt, 0);
		while (--ilen >= 0)
			write(1, "0", 1);
		(*dt)->w = 0;
	}
}

int		ftpf_numbers(t_pfdata **dt, va_list *data)
{
	const char	*src;
	
	src = ftpf_get(dt, data);
	ft_lstfromstr(&(*dt)->data, &src);
	ftpf_numbers_put_lefpad(dt);
	ftpf_numbers_put_sign(dt);
	return (0);
}
