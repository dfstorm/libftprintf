#include "libft.h"

int		ftpf_ef(char c)
{
	char ref[15] = "sSpdDioOuUxXcC%";
	int i;
	
	i = -1;
	while (ref[++i] != '\0')
		if (ref[i] == c)
			return (c);
	return (-1);
}


char	*ftpf_extract(const char **str, int *ipos)
{
	int i;

	i = (*ipos) - 1;
	while ((*str)[++i] != '\0')
		if (ftpf_ef((*str)[i]) > 0)
			return (ft_strsub((*str), (*ipos), ((*ipos) - i)));
	return (NULL);
}
