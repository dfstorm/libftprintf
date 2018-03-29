#include "libft.h"

int		ft_lstcount(t_list **d)
{
	t_list	*tmp;
	int		i;
	
	tmp = (*d);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	free(tmp);
	return (i);
}
