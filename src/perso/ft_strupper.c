#include "libft.h"

char	*ft_strupper(char *str)
{
	int i;
	
	i = -1;
	while (str[++i] != '\0')
		str[i] = ft_toupper(str[i]);
	return (str);
}
