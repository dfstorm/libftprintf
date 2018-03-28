#include "libft.h"

void	ftpf_doaddprexif(t_list **lst, const char *prefix)
{
	ft_lstfromstr(lst, &prefix);
}

void	ftpf_addprefix(t_list **lst, t_list **flags, char *t)
{
	t_list	*f;
	char	st;
	f = (*flags);
	if ((*t) == 'p')
		ftpf_doaddprexif(lst, "0x");
	
	
	
	
	while (f)
	{
		st = (char) f->content;
		if (st == '#')
		{
			if ((*t) == 'o' || (*t) == 'O')
				ftpf_doaddprexif(lst, "#");
		}
		f = f->next;
	}


}
