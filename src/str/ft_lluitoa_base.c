#include "libft.h"

char	ftlluibc(int i)
{
	if (i <= 9)
		return (i + '0');
	else
		return ((i - 10) + 'a');
}

char	*ft_lluitoa_base(long long unsigned int nbr, long long unsigned int base)
{
	int		tmp;
	int		i;
	char	*str;

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
		*str-- = ftlluibc((nbr % base) * 1);
		nbr /= base;
	}
	return (str + 1);
}
