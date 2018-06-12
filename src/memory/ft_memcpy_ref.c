#include "../../includes/libft.h"

void	*ft_memcpy_ref(void **dst, const void *src, size_t n)
{
	char *odst;
	char *osrc;
	size_t x;

	x = -1;
	odst = (char*)(*dst);
	osrc = (char*)src;
	while (++x < n)
		odst[x] = osrc[x];
	return (*dst);
}
