#include "../../includes/libft.h"

int		ft_isprintable(int c)
{
	if ((c >= 7 && c <= 13) || (c >= 20 && c<= 126))
		return (1);
	return (0);
}
