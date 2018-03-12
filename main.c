#include <stdio.h>
#include <wchar.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
int		main(int argc, char **argv)
{
	unsigned int i;
	
	i = 46;
	
	if (i) {}
	if (argc || argv) {}
	   
	   printf("Thier: %p\n", &i);
	ft_printf("Mine-: %p\n", &i);
	
	ft_putstr("\n");
	return (0);
}
