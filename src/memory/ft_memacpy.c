
#include "../../includes/libft.h"

void	*ft_memacpy(void *dst, const void *src, size_t n)
{
	ft_putstr("\n>>");
	ft_putstr(src);
	ft_putstr("<<\n");
	char *odst;
	char *osrc;


	odst = (char*)dst;
	osrc = (char*)src;
	while (n--)
		*(odst++) = *(osrc++);
	return (dst);
}
