#include "../../includes/libft.h"

void	*ft_memcpy_ref(void **dst, const void *src, size_t n)
{
	char *odst;
	char osrc;

	if(src || n || osrc){}

	odst = (char *) (*dst);
	//osrc = (char) (src);
	odst[0] = 'A';

	return dst;
}
