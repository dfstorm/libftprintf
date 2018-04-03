//#include <stdio.h>
//#include <wchar.h>


int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
void	ft_putnbr(int i);

int		main(int argc, char **argv)
{
/*
	int		t;
	unsigned int		p;
	
	p = 34;
	
	t = 34;
	//wchar_t c = L'µ';
	wchar_t *s = L"abwecdef";
	//wchar_t c = L'L';
*/
	//int r1;
	//int r2;
	char i[2] = "a";
	//int	i;
	//i = 23;

	//if (i || t || s) {}
	if (argc || argv) {}

	ft_printf("Pouette %s\n", i);
	
	
	//r2 =    printf("%i\n", i);
	
	//ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
	
/*
	r1 = ft_printf("%10x\n", p);
	r2 =    printf("%10x\n", p);
	ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
	
	r1 = ft_printf("Mine-: [%10u]\n", p);
	r2 =    printf("Thier: [%10u]\n", p);
	ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
	
	r1 = ft_printf("Mine-: [%10S]\n", s);
	r2 =    printf("Thier: [%10ls]\n", s);
	ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
	
	r1 = ft_printf("Mine-: [%-20p]\n", s);
	r2 =    printf("Thier: [%-20p]\n", s);
	ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
*/
	
	return (0);
}
