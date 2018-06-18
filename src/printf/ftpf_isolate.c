/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftpf_isolate.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:08:08 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:08:25 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ftpf_ist(char c)
{
	int i;
	char s[16] = "sSpdDioOuUxXcC";

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ftpf_isolate_v1(const char **str, int *ipos, int *size)
{
	int		i;
	char	*src;

	src = NULL;

	i = (*ipos);
	if ((*str)[i + 1] == '%')
	{
		ft_putchar((*str)[i]);
		(*ipos) = (*ipos) + 1;
		(*size) = (*size) + 1;
		return (NULL);
	}
	while ((*str)[++i] != '\0')
	{
		if ((*str)[i] == '%')
		{
			(*ipos) = i;
			(*size) = (*size) + 1;
			ft_putchar((*str)[i]);
			return (NULL);
		}
		if (ftpf_ist((*str)[i]) == 1)
		{
			src = ft_strsub((*str), (*ipos), (i - (*ipos) + 1));
			(*ipos) = i;
			break ;
		}
	}
	return (src);
}

char	*ftpf_isolate(const char **str, int *ipos, int *size)
{
	char	*src;
	int		i;

	i = (*ipos);
	while ((*str)[++i] != '\0')
	{
		if ((*str)[i] == '%')
		{
			ft_putchar((*str)[i]);
			(*size) = (*size) + 1;
			(*ipos) = i;
			return (NULL);
		}
		if (ftpf_ist((*str)[i]) == 1)
		{
			src = ft_strsub((*str), (*ipos), (i - (*ipos) + 1));
			(*ipos) = i;
			return (src);
		}
	}
	return (NULL);
}
