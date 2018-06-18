/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/14 16:04:14 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 18:58:40 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"
#define IS_SPACE(c, d) (c == d)

static int		count_words(char *s, char delimiter)
{
	int i;
	int words;

	i = -1;
	words = 0;
	while (s[++i])
		if (((i != 0 && IS_SPACE(s[i], delimiter) &&
		!IS_SPACE(s[i - 1], delimiter)) ||
		(s[i + 1] == '\0' && !IS_SPACE(s[i], delimiter))))
			words++;
	return (words);
}

static char		*get_word(char *s, char delimiter)
{
	int		i;
	int		size;
	char	*word;

	i = -1;
	size = 0;
	while (s[++i] && !IS_SPACE(s[i], delimiter))
		size++;
	word = malloc(sizeof(char) * (size + 1));
	word[size] = '\0';
	while (*s && !IS_SPACE(*s, delimiter))
	{
		*word++ = *s;
		s++;
	}
	return (word - size);
}

char			**ft_strsplit(char *s, char delimiter)
{
	int		size;
	char	**tab;
	char	*str;

	if (!s)
		return (NULL);
	size = count_words(s, delimiter);
	if (!(tab = malloc((size + 1) * sizeof(char*))))
		return (NULL);
	tab[size] = 0;
	str = s;
	while (*str)
	{
		if (!IS_SPACE(*str, delimiter))
		{
			*tab++ = get_word(str, delimiter);
			str += ft_strlen(get_word(str, delimiter)) - 1;
		}
		str++;
	}
	return (tab - size);
}
