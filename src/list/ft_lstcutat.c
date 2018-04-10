#include "libft.h"

void	ft_lstcutat(t_list **lst, int count)
{
	t_list	*ref;
	int		i;
	t_list	*next;

	i = 0;
	ref = (*lst);
	while ((*lst))
	{
		i = i + 1;
		next = (*lst)->next;
		if (i == count)
		{
			(*lst)->next = NULL;
		}
		if (i > count)
		{
			free((*lst)->content);
			(*lst)->content = NULL;
			free((*lst));
			(*lst) = NULL;
		}
		(*lst) = next;
	}
	(*lst) = ref;
}
