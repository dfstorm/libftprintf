#include "libft.h"

void	ft_putlchar(wchar_t c)
{
	write(1, &c, sizeof(c));
}
