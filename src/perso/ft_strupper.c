#include "libft.h"

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
