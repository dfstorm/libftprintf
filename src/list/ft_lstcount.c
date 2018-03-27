#include "libft.h"

int		ft_lstcount(t_list **d)
{
	t_list	*tmp;
	int		i;
	
	i = -1;
	tmp = *d;
	while (tmp)
	{
		if(tmp->content != NULL)
			i++;
		tmp = tmp->next;
	}
	free(tmp);
	return (i);
}
