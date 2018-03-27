#include "libft.h"

int		ftpf_ist(char c)
{
	int i;
	char s[16] = "sSpdDioOuUxXcC%";

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ftpf_isolate(const char **str, int *ipos)
{
	int		i;
	char	*src;
	
	src = NULL;

	i = (*ipos);
	if ((*str)[1] == '%')
	{
		src = ft_strsub((*str), (*ipos), 1);
		(*ipos) = (*ipos) + 1;
		return (src);
	}
	while ((*str)[++i] != '\0')
	{
		if (ftpf_ist((*str)[i]) == 1)
		{
			src = ft_strsub((*str), (*ipos), (i - (*ipos) + 1));
			(*ipos) = i;
			break ;
		}
	}
	return (src);
}
