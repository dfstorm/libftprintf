/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftpf_strings.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:09:47 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 16:40:33 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ftpf_strings_null(void)
{
	char *s;

	s = ft_strnew(7);
	ft_memcpy(s, "(null)", 7);
	return (s);
}

int		ftpf_strings_w(t_pfdata **dt, va_list *data)
{
	wchar_t	c;
	wchar_t	*s;
	int i;
	int l;

	l = 1;
	if ((*dt)->t == 'C' || (*dt)->t == 'c')
	{
		c = va_arg((*data), wchar_t);
		(*dt)->data = ft_lstnew(&c, sizeof(wchar_t));
	}
	else if ((*dt)->t == 'S' || (*dt)->t == 's')
	{
		s = va_arg((*data), wchar_t *);
		l = i = ft_strlenw(s);
		while (--i >= 0)
			ft_lstadd(&(*dt)->data, ft_lstnew(&s[i], sizeof(char)));

	}
	return (l);
}

int		ftpf_string_n(t_pfdata **dt, va_list *data)
{
	char	c;
	int		l;
	char	*tmp;
	char	*va;

	l = 1;
	if ((*dt)->t == 'c')
	{
		c = va_arg((*data), unsigned int);
		(*dt)->data = ft_lstnew(&c, sizeof(char));
	}
	else if ((*dt)->t == 's')
	{
		va = va_arg((*data), char *);
		if (va == NULL)
			tmp = ftpf_strings_null();
		else
			tmp = ft_strdup(va);
		ft_lstfromstr(&(*dt)->data, &tmp);
		l = ft_strlen(tmp);
		free(tmp);
	}
	return (l);
}
int		ftpf_string_p(t_pfdata **dt, va_list *data)
{
	char	*src;

	if ((*dt)->t == 'p')
	{
		src = ft_luitoa_base(va_arg((*data), size_t), 16);
		ft_lstfromstr(&(*dt)->data, &src);
		ftpf_numbers_put_ox(dt, 1);
		free(src);
	}
	return (0);
}

void	ftpf_strings(t_pfdata **dt, va_list *data)
{
	int	l;

	l = ftpf_getlength(dt);
	if (l == 3 || (*dt)->t == 'C' ||  (*dt)->t == 'S')
		ftpf_strings_w(dt, data);
	else if ((*dt)->t == 'c' ||  (*dt)->t == 's')
		ftpf_string_n(dt, data);
	else if ((*dt)->t == 'p')
		ftpf_string_p(dt, data);
}
