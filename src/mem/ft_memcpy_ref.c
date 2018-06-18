#include "../../includes/libft.h"

void	*ft_memcpy_ref(void **dst, const void **src, size_t n)
{
	char *odst;
	char *osrc;
	size_t	nb;

	nb = -1;
	odst = (char*) (*dst);
	osrc = (char*) (*src);

	ft_putchar(*osrc);

	while (++nb < n)
	{
		odst[nb] = *osrc;
		ft_putchar(odst[nb]);
	}


	dst = (void *) odst;
	return (dst);
}
