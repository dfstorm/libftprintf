#include <stdio.h>
#include <wchar.h>


int		ft_printf(const char *str, ...);
void	ft_putstr(char *str);
void	ft_putnbr(int i);
void	ft_putchar(int d);

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

	int r1;
	int r2;
	char i[3] = "ab";
	//int	i;
	//i = 23;
*/
	//if (i || t || s) {}
	if (argc || argv) {}

	//int r1;
	//int r2;
	
	//r2 = 0;
	//r1 = 0;
	printf("Test 0:\n");
	
	int i;
	i = 0;
	
/*
 * 
 
# 0046 (int)
  ft_printf("@moulitest: %#.x %#.0x", 0, 0);
  1. (   15) -->@moulitest: 0 0<--
  2. (   13) -->@moulitest:  <--
  
# 0093 (int)
  ft_printf("@moulitest: %.o %.0o", 0, 0);
  1. (   15) -->@moulitest: 0 0<--
  2. (   13) -->@moulitest:  <--
  
# 0095 (int)
  ft_printf("@moulitest: %#.o %#.0o", 0, 0);
  1. (   13) -->@moulitest:  <--
  2. (   15) -->@moulitest: 0 0<--

 
 */
 	//i = ft_printf("@moulitest:[%10.0i] [%10.5i]", 0, -1);
	
	i = ft_printf("%05d", 42);
	//i = ft_printf("%03.2d", 1);
	//ft_printf("yeah %i ", i);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	
	
	/*
	ft_printf("Test 1:\n"); 
	r1 = ft_printf("Mine-: %s\n", i);
	r2 =    printf("their: %s\n", i);
	
	
	
	ft_printf("Test 2:\n");
	r1 = ft_printf("%10x\n", p);
	r2 =    printf("%10x\n", p);
	ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
	
	ft_printf("Test 3:\n");
	r1 = ft_printf("Mine-: [%10u]\n", p);
	r2 =    printf("Thier: [%10u]\n", p);
	ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
	
	ft_printf("Test 4:\n");
	r1 = ft_printf("Mine-: [%10S]\n", s);
	r2 =    printf("Thier: [%10ls]\n", s);
	ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
	
	ft_printf("Test 5:\n");
	r1 = ft_printf("Mine-: [%-20p]\n", s);
	r2 =    printf("Thier: [%-20p]\n", s);
	ft_printf("=== Mine: %i, Their: %i ===\n", r1, r2);
*/
	
	return (0);
}
