#include "libft.h"

void	ft_lstfromstr(t_list **lst, char **str)
{
	int		i;
	char	*t;
	t_list	*tmp;
	char	r;

	if((*str))
	{
		t = ft_strdup((*str));
		i = ft_strlen(t);
		while (--i >= 0)
		{
			r = t[i];
			if(ft_isprintable(t[i]))
			{
				tmp = ft_lstnew(&r, sizeof(char));
				ft_lstadd(lst, tmp);
			}
		}
		free(t);
	}
	
}
