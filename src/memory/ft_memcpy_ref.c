#include "../../includes/libft.h"

void	*ft_memcpy_ref(void **dst, const void **src, size_t n)
{
	char *odst;
	char *osrc;
	size_t	nb;

	nb = -1;
	odst = (char*)(*dst);
	osrc = (char*)(*src);

	while (++nb < n)
		odst[nb] = osrc[nb];
	return (dst);
}
