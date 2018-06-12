#include "../../includes/libft.h"

void	*ft_memcpy_ref(void **dst, const void *src, size_t n)
{
	char *odst;
	char osrc;

	osrc = 'A';
	if(src || n || osrc){}

	odst = (char *) (*dst);
	//osrc = (char) (src);
	odst[0] = (char) 'A';

	return odst;
}
