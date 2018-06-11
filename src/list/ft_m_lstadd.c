
#include "../../includes/libft.h"

void	ft_m_lstadd(t_list **list, t_list *new)
{
	if(*list != NULL)
	{
		new->next = *list;
	}
	list = &new;
}
