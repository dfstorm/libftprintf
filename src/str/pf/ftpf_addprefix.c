#include "libft.h"

void	ftpf_doaddprexif(t_list **lst, const char *prefix)
{
	if(lst || prefix) {}
	//ft_lstfromstr(lst, &prefix);
}

void	ftpf_doprefix(t_pfdata **dt, char *f)
{
	if (f == NULL)
		return ;
	if (ftpf_iscinlist(&(*dt)->f, '#'))
	{
		if ((*dt)->t == 'o' || (*dt)->t == 'O')
			ftpf_doaddprexif(&(*dt)->data, "0");
		if ((*dt)->t == 'x')
			ftpf_doaddprexif(&(*dt)->data, "0x");
		if ((*dt)->t == 'X')
			ftpf_doaddprexif(&(*dt)->data, "0X");	
	}
}

void	ftpf_addprefix(t_pfdata **dt)
{
	char	*f;
	t_list	*flags;
	
	flags = (*dt)->f;
	if ((*dt)->t == 'p')
		ftpf_doaddprexif(&(*dt)->data, "0x");
	while (flags)
	{
		f = (char *) flags->content;
		ftpf_doprefix(dt, f);		
		flags = flags->next; 
	}
}
