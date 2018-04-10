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
				tmp[0] = ' ';
			ft_lstadd(&(*dt)->data, ft_lstnew(tmp, sizeof(char)));
			free(tmp);
		}
	}
}

int		ftpf_numbers_counts(t_list **list)
{
	t_list	*ref;
	int		nb;
	
	ref = (*list);
	nb = (ftpf_getcfl(list) == '-' ? -1 : 0);
	while (ref)
	{
		nb = nb + 1;
		ref = ref->next;
	}
	return (nb);
}

void	ftpf_numbers_put_lefpad(t_pfdata **dt, int *size)
{
	int		ilen;
	char 	c;
	int		writen;
	t_list	*tmp;

	writen = ((*dt)->p > 0 ? (*dt)->p - ftpf_numbers_counts(&(*dt)->data) : -1);
	//ftpf_tmp_printpfdata(dt);

	c = ftpf_getcfl(&(*dt)->data);
	if (ftpf_iscinlist(&(*dt)->f, '0') && !ftpf_iscinlist(&(*dt)->f, '-'))
	{
		if ((*dt)->w == 0)
			return ;
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
				if(writen != 0)
				{
					(*dt)->data->content = "0";
					writen--;
				}
				else
				{
					tmp = (*dt)->data->next;
					free((*dt)->data->content);
					free((*dt)->data);
					(*dt)->data = tmp;
					ilen++;
				}
			} else {
				c = '0';
				if (ftpf_iscinlist(&(*dt)->f, '+'))
					write(1, "+", 1);
				else if (ftpf_iscinlist(&(*dt)->f, ' '))
					write(1, " ", 1);
				else if(writen != 0)
				{
					if(writen != 0)
					{
						writen--;
						ft_lstadd(&(*dt)->data, ft_lstnew(&c, sizeof(char)));
						(*size)--;
					}
				}
			}
			(*size)++;
			
		}
		
		while (--ilen >= 0)
		{
			
			if ((*dt)->p < 0 || ((*dt)->p >= 0 && writen > 0))
			{
				c = '0';
				writen--;
			}
			else
			{
				c = ' ';
			}
			ft_lstadd(&(*dt)->data, ft_lstnew(&c, sizeof(char)));
		}
		
		if ((*dt)->p > 0)
			(*dt)->w = ((*dt)->w > (*dt)->p ? (*dt)->w - (*dt)->p : 0);
		else
			(*dt)->w = 0;
	
	}
}

int		ftpf_numbers(t_pfdata **dt, va_list *data)
{
	char	*src;
	int		size;
	
	
	size = 0;
	src = ftpf_get_n(dt, data);
	ft_lstfromstr(&(*dt)->data, &src);
	free(src);
	ftpf_numbers_put_lefpad(dt, &size);
	ftpf_numbers_put_ox(dt, 1);
	ftpf_numbers_put_sign(dt);
	return (size);
}
