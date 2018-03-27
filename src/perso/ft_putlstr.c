#include "libft.h"

void	ft_putlstr(wchar_t *s)
{
	int	i;
	
	i = -1;
	while (s[++i] != '\0')
		ft_putlchar(s[i]);
}
