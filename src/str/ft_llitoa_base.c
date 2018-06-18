#include "../../includes/libft.h"

char	ftllibc(int i)
{
	if (i <= 9)
		return (i + '0');
	else
		return ((i - 10) + 'a');
}

char	*ft_llitoa_base(long long int nbr, long long int base)
{
	long long int	tmp;
	int				i;
	int				mod;
	char			*str;

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
		*str-- = ftllibc((nbr % base) * (mod ? -1 : 1));
		nbr /= base;
	}
	return (str + 1 - mod);
}
