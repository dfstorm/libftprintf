#include "../../includes/libft.h"

void	*ft_memcpy_ref(void **dst, const void *src, size_t n)
{
	char *odst;
	//char *osrc;
	size_t x;
	if(src){}
	x = -1;
	odst = (char*)(*dst);
	//osrc = (char*) src;
	while (++x < n)
		odst[x] = 'A';
	return (*dst);
}
