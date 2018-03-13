#include <stdio.h>
#include <wchar.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
int		main(int argc, char **argv)
{
	long unsigned int i;
	//wchar_t c = L'µ';
	wchar_t c;
	c = 0xF8;
	i = 1;
	
	if (i) {}
	if (argc || argv) {}
	   
	   printf("Thier: [%lc] ff \n", c);
	ft_printf("Mine-: [%C] \n", c);
	
	ft_putstr("\n");
	return (0);
}
