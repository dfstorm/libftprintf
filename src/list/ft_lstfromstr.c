#include "libft.h"

void	ft_lstfromstr(t_list **lst, char **str)
{
	int		i;
	char	*t;
	
	t = ft_strdup((*str));
	i = ft_strlen(t) + 1;
	while (--i >= 0)
	{
		
		if(ft_isprintable(t[i]))
		{
			ft_putchar('p');
			ft_lstadd(lst, ft_lstnew(&t[i], 1));
		}
	}
	free(t);
}
