#include "libft.h"

int		ft_findcis(char **haystack, char item)
{
	int	i;

	i = -1;
	if ((*haystack))
		while ((*haystack)[++i])
			if ((*haystack)[i] == item)
				return (i);
	return (-1);
}

