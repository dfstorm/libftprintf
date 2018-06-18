/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftpf_types.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:09:59 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:10:09 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ftpf_gettype(t_pfdata **dt)
{
	char	s[16] = "sSpdDioOuUxXcC%";
	int		i = -1;
	int		x;

	x = ft_strlen((*dt)->input) - 1;
	while (s[++i] != '\0')
		if (s[i] == (*dt)->input[x])
			(*dt)->t = (s[i]);
}

void		ftpf_getflagsnw(t_pfdata **dt, va_list *data)
{
	int		pos;

	pos = 0;
	while ((*dt)->input[++pos])
	{
		if ((*dt)->input[pos] == '-' || (*dt)->input[pos] == '+' ||
			(*dt)->input[pos] == ' ' || (*dt)->input[pos] == '#' ||
			(*dt)->input[pos] == '0')
			ft_lstadd(&(*dt)->f, ft_lstnew(&(*dt)->input[pos], sizeof(void)));
		else
			break ;
	}
	if ((*dt)->input[pos] == '*')
		(*dt)->w = va_arg((*data), int);
	else
	{
		while (ft_isdigit((*dt)->input[pos]))
		{
			(*dt)->w = (*dt)->w * 10;
			(*dt)->w += (*dt)->input[pos++] - '0';
		}
	}
}

void		ftpf_getprecision(t_pfdata **dt, va_list *data)
{
	int	pos;

	pos = -1;
	while ((*dt)->input[++pos])
		if ((*dt)->input[pos] == '.' || (ftpf_islflag((*dt)->input[pos] == 1)))
			break ;
	if ((*dt)->input[pos] == '.')
	{
		pos++;
		if ((*dt)->input[pos] == '*')
			(*dt)->p = va_arg((*data), int);
		else
		{
			(*dt)->p = 0;
			while (ft_isdigit((*dt)->input[pos]))
			{
				(*dt)->p = (*dt)->p * 10;
				(*dt)->p = (*dt)->p + ((*dt)->input[pos] - '0');
				pos++;
			}

		}
	}
}

t_pfdata	*ftpf_initcontainer()
{
	t_pfdata	*dt;

	dt = (t_pfdata *)malloc(sizeof(*dt));
	if (dt == NULL)
		return (NULL);
	dt->data = NULL;
	dt->f = NULL;
	dt->input = NULL;
	dt->wspace_char = ' ';
	dt->w = 0;
	dt->p = -1;
	dt->t = 0;
	dt->s = 0;
	return (dt);
}

void		ftpf_types(char **input, va_list *data, int *size)
{
	t_pfdata	*dt;

	dt = ftpf_initcontainer();
	if (dt == NULL)
		ft_putstr("\nWarning: Memory allocation error.\n");
	dt->input = ft_strdup((*input));
	ftpf_gettype(&dt);
	ftpf_getflagsnw(&dt, data);
	ftpf_getprecision(&dt, data);
	if (dt->t == 's' || dt->t == 'S' || dt->t == 'p'
		|| dt->t == 'c' || dt->t == 'C')
		ftpf_strings(&dt, data);
	else
	{
		(*size) = (*size) + ftpf_numbers(&dt, data);
	}
	if(dt->w > dt->s && dt->s > 0)
		dt->w = dt->w - dt->s;
	else
		(*size) = (*size) + (dt->s > 0 ? dt->s : 0);
	(*size) = (*size) + ftpf_write(&dt);
	ft_lstwipe(&dt->data);
	ft_lstwipe(&dt->f);
	free(dt->input);
	free(dt);
}
