#include "../../includes/libft.h"

void	ft_lstwipe(t_list **list)
{
	t_list	*erase;
	t_list	*next;

	erase = *list;
	while (erase)
	{
		next = erase->next;
		free(erase->content);
		erase->content = NULL;
		free(erase);
		erase = NULL;
		erase = next;
	}
	*list = NULL;
}
