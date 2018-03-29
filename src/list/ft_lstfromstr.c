#include "libft.h"

void	ft_lstfromstr(t_list **lst, const char **str)
{
	int		i;
	
	i = ft_strlen((*str)) + 1;
	while (--i >= 0)
		if (&(*str)[i])
			if(ft_isprintable((*str)[i]))
				ft_lstadd(lst, ft_lstnew(&(*str)[i], sizeof(char)));
}
