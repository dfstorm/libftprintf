#include <stdio.h>
#include <wchar.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
int		main(int argc, char **argv)
{
	long unsigned int i;
	//wchar_t c = L'µ';
	char c;
	c = 'd';
	i = 1;
	
	if (i) {}
	if (argc || argv) {}
	
	   
	   printf("Thier: %% [%c] \n", c);
	ft_printf("Mine-: %% [%c] \n", c);
	
	ft_putstr("\n");
	return (0);
}
