#include "libft.h"

void	ft_lstwipe(t_list **list)
{
	t_list	*erase;
	t_list	*next;

	erase = *list;
	while (erase)
	{
		ft_putchar('w');
		next = erase->next;
		free(erase);
		erase = next;
	}
	*list = NULL;
}
