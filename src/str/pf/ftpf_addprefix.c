#include "libft.h"

void	ftpf_doaddprexif(t_list **lst, const char *prefix)
{
	ft_lstfromstr(lst, &prefix);
}

void	ftpf_doprefix(t_pfdata **dt, char *f)
{
	if (f == NULL)
		return ;
	if (f[0] == '#')
	{
		if ((*dt)->t == 'o' || (*dt)->t == 'O')
		{
			ftpf_doaddprexif(&(*dt)->data, "0");
		}
		else
		{
			
		}
	}
}

void	ftpf_addprefix(t_pfdata **dt)
{
	char *f;

	if ((*dt)->t == 'p')
		ftpf_doaddprexif(&(*dt)->data, "0x");
	while ((*dt)->f)
	{
		f = (char *) (*dt)->f->content;
		ftpf_doprefix(dt, f);		
		(*dt)->f = (*dt)->f->next; 
	}
}
