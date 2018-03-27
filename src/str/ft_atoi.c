/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/09/21 11:31:23 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 10:56:52 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int mod;
	int res;

	mod = 1;
	res = 0;
	while (*str == ' ' || (*str >= '\a' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		mod = *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * mod);
}
