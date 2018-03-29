#include "libft.h"

char		ftpf_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

void	ftpf_getflagsnw(char **input, t_pfdata **dt)
{
	int		pos;

	pos = 0;
	while ((*input)[++pos])
	{
		if (ftpf_isflag((*input)[pos]))
			ft_lstadd(&(*dt)->f, ft_lstnew(&(*input)[pos], sizeof(char)));
		else
			break ;
	}
	while (ft_isdigit((*input)[pos]))
	{
		(*dt)->w = (*dt)->w * 10;
		(*dt)->w += (*input)[pos++] - '0';
	}
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
	ftpf_getflagsnw(input, &dt);
	dt->p = ftpf_getprecision(input);
	
	if (dt->w < 0)
		dt->w = va_arg((*data), int);
	if (dt->p < 0)
		dt->p = va_arg((*data), int);
	if (dt->t == 's' || dt->t == 'S' || dt->t == 'p'
		|| dt->t == 'c' || dt->t == 'C')
		ftpf_strings(data, &dt->t, &dt->data);
	else
		ftpf_numbers(data, &dt->t, &dt->data);
	ftpf_addprefix(&dt);
	(*size) = ftpf_write(&dt);
	free(dt);
}
