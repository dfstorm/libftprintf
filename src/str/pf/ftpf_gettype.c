#include "libft.h"

char	ftpf_gettype(char **input)
{
	char	s[16] = "sSpdDioOuUxXcC%";
	int		i = -1;
	int		x;
	
	x = ft_strlen((*input)) - 1;
	while (s[++i] != '\0')
		if (s[i] == (*input)[x])
			return (s[i]);
	return (0);
}
