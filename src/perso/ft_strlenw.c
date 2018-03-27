#include "libft.h"

int		ft_strlenw(wchar_t *s)
{
	int i;
	
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
