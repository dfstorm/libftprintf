#include "../../includes/libft.h"

void	*ft_memcpy_ref(void **dst, const void *src, size_t n)
{
	char *odst;
	char *osrc;

	odst = (char*)(*dst);
	osrc = (char*)(src);
	while (n--)
		*(odst++) = *(osrc++);
	return (*dst);
}
