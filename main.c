#include <stdio.h>
#include <wchar.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
void	ft_putnbr(int i);

int		main(int argc, char **argv)
{
	int r1;
	int r2;
	char i;
	int		t;
	unsigned long int		p;
	
	p = 34;
	
	t = 34;
	//wchar_t c = L'µ';
	char *s = "abcdef";
	//wchar_t c = L'L';
	
	i = 'A';
	
	if (i || t || s) {}
	if (argc || argv) {}

	r1 = ft_printf("Mine-: [%+010i]\n", t);
	r2 =    printf("Thier: [%+010i]\n", t);
	
	r1 = ft_printf("Mine-: [%#10X]\n", p);
	r2 =    printf("Thier: [%#10X]\n", p);
	
	r1 = ft_printf("Mine-: [%10U]\n", p);
	r2 =    printf("Thier: [%10lu]\n", p);
	
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
