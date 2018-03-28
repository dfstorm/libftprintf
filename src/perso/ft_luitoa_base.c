#include "libft.h"

char	ftluibc(int i)
{
	if (i <= 9)
		return (i + '0');
	else
		return ((i - 10) + 'a');
}

char	*ft_luitoa_base(long unsigned int nbr, size_t base)
{
	long unsigned int	tmp;
	unsigned int		i;
	char				*str;

	tmp = nbr;
	i = 1;
	while (tmp /= base)
		i++;
	if (!(str = malloc((i + 1) * sizeof(char))))
		return (NULL);
	str += i;
	*str-- = '\0';
	if (nbr == 0)
		*str-- = '0';
	while (nbr)
	{
		*str-- = ftluibc(nbr % base);
		nbr /= base;
	}
	return (str + 1);
}
