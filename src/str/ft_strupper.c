/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strupper.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/19 16:06:40 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/19 16:06:41 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strupper(char *str)
{
	int		i;
	char	*new;

	new = ft_strdup(str);
	free(str);
	i = -1;
	while (new[++i] != '\0')
		new[i] = ft_toupper(new[i]);
	return (new);
}
