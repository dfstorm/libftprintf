#include "libft.h"

int		ftpf_isc(char t)
{
		if(t == 's' || t == 'S' || t == 'p' || t == 'c' || t == 'C')
			return (1);
		else
			return (0);
}

t_list	*ftpf_getflagsnw(char **input, int *w)
{
	char	tmp;
	int		pos;
	t_list	*flags;
	t_list	*item;

	pos = 0;
	flags = ft_lstnew(NULL, sizeof(void));
	while ((*input)[++pos])
	{
		if ((ft_isdigit((*input)[pos]) && (*input)[pos] != '0')
			|| (*input)[pos] == '.' || (*input)[pos] == '*'
			|| ftpf_islflag((*input)[pos]))
			break ;
		tmp = (*input)[pos];
		item = ft_lstnew(&tmp, sizeof(char));
		ft_lstadd(&flags, item);
	}
	if ((*input)[pos] == '*')
		(*w) = -1;
	while (ft_isdigit((*input)[pos]))
	{
		(*w) = (*w) * 10;
		(*w) = (*w) + ((*input)[pos++] - '0');
	}
	return (flags);
}

int		ftpf_getprecision(char **input)
{
	int	pos;
	int p;
	
	p = 0;
	pos = -1;
	while ((*input)[++pos])
		if ((*input)[pos] == '.' || (ftpf_islflag((*input)[pos] == 1)))
			break ;
	if ((*input)[pos] == '.')
	{
		pos++;
		if ((*input)[pos] == '*')
			p = -1;
		else
		{
			while (ft_isdigit((*input)[pos]))
			{
				p = p * 10;
				p = p + ((*input)[pos] - '0');
				pos++;
			}
		}
	}
	return (p);
}

void	ftpf_types(char **input, va_list *data, int *size)
{
	t_list	*item;
	char	t;
	t_list	*f;
	int		w;
	int		p;

	w = 0;
	t = ftpf_gettype(input);
	f = ftpf_getflagsnw(input, &w);
	p = ftpf_getprecision(input);
	
	if(w || t || f || p) {}

	if (w < 0)
		w = va_arg((*data), int);
	if (p < 0)
		p = va_arg((*data), int);
	if (ftpf_isc(t) == 1)
		ftpf_strings(data, &t, &item);
	else
		ftpf_numbers(data, &t, &item);
	ftpf_addprefix(&item, &f, &t);
		
	(*size) = ftpf_write(&item, p, w, &f);
	
}
