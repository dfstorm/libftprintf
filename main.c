#include <stdio.h>
#include <wchar.h>


int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
void	ft_putnbr(int i);

int		main(int argc, char **argv)
{
	int r1;
	int r2;
	
	int		t;
	unsigned int		p;
	
	p = 34;
	
	t = 34;
	//wchar_t c = L'µ';
	char *s = "abcdef";
	//wchar_t c = L'L';
	
	int i;
	i = 23;
	
	if (i || t || s) {}
	if (argc || argv) {}

	r1 = ft_printf("Mine-: [%i]\n", i);
	r2 =    printf("Thier: [%i]\n", i);
	
	r1 = ft_printf("Mine-: [%10x]\n", p);
	r2 =    printf("Thier: [%10x]\n", p);
	
	r1 = ft_printf("Mine-: [%10u]\n", p);
	r2 =    printf("Thier: [%10u]\n", p);
	
	r1 = ft_printf("Mine-: [%-10s]\n", s);
	r2 =    printf("Thier: [%-10s]\n", s);
	
	r1 = ft_printf("Mine-: [%-20p]\n", s);
	r2 =    printf("Thier: [%-20p]\n", s);
	
	ft_putstr("\nNombre de char / error:\nMine: ");
	ft_putnbr(r1);
	ft_putstr("\ntheir: ");
	ft_putnbr(r2);
	ft_putstr("\n");
	
	return (0);
}
