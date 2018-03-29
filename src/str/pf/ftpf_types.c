#include "libft.h"

int			ftpf_isc(char t)
{
	if(t == 's' || t == 'S' || t == 'p' || t == 'c' || t == 'C')
		return (1);
	else
		return (0);
}

t_list		*ftpf_getflagsnw(char **input, int *w)
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

int			ftpf_getprecision(char **input)
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

t_pfdata	*ftpf_initcontainer()
{
	t_pfdata	*dt;
	
	dt = (t_pfdata *)malloc(sizeof(*dt));
	dt->data = ft_lstnew(NULL, 0);
	dt->f = ft_lstnew(NULL, 0);
	dt->w = 0;
	dt->p = 0;
	dt->t = 0;
	dt->s = 0;
	return (dt);
}

void		ftpf_types(char **input, va_list *data, int *size)
{
	t_pfdata	*dt;
	
	dt = ftpf_initcontainer();
	
	dt->w = 0;
	dt->t = ftpf_gettype(input);
	dt->f = ftpf_getflagsnw(input, &dt->w);
	dt->p = ftpf_getprecision(input);
	
	if (dt->w < 0)
		dt->w = va_arg((*data), int);
	if (dt->p < 0)
		dt->p = va_arg((*data), int);
	if (ftpf_isc(dt->t) == 1)
		ftpf_strings(data, &dt->t, &dt->data);
	else
		ftpf_numbers(data, &dt->t, &dt->data);
	ftpf_addprefix(&dt);
	(*size) = ftpf_write(&dt->data, dt->p, dt->w, &dt->f);
	free(dt);
}
