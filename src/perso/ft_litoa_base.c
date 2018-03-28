
#include "libft.h"

char	ftlibc(long signed int i)
{
	if (i <= 9)
		return (i + '0');
	else
		return ((i - 10) + 'a');
}

char	*ft_litoa_base(long signed int nbr, int base)
{
	int		tmp;
	int		i;
	int		mod;
	char	*str;

	tmp = nbr;
	i = 1;
	mod = nbr < 0;
	while (tmp /= base)
		i++;
	if (!(str = malloc((i + 1 + mod) * sizeof(char))))
		return (NULL);
	if (mod)
		*str++ = '-';
	str += i;
	*str-- = '\0';
	if (nbr == 0)
		*str-- = '0';
	while (nbr)
	{
		*str-- = ftlibc((nbr % base) * (mod ? -1 : 1));
		nbr /= base;
	}
	return (str + 1 - mod);
}
