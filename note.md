
# libft - Printf dev

%[parameter][flags][width][.precision][length]type

	- Conversion sSpdDioOuUxXcC						[OK]
	- %%											[OK]
	- Vous devez gérer les flags #0-+ et espace
	- Vous devez gérer la taille minimum du champ
	- Vous devez gérer la précision
	- Vous devez gérer les flags hh h l ll j z


## usefull command

make -C ./ fclean && make -C ./ &&
clang -Wall -Wextra -Werror -I includes -o main.o -c main.c &&
clang -o test_gnl main.o -I includes -L  -lft

---

make -C ./ fclean && make -C ./ && gcc -o prog main.c libftprintf.a && ./prog


Un printf(); does not crash ?
It does

Donc, on avance dans la chaine.
Si pas un joker: On put le char.
Si joker: On isole la requete ?

BUT: Entree diverse, on sors en char.

o => Octal to char.

102 = "102".

# -- -- -- -- -- -- -- -- -- #
#	Hexa = 0123456789ABCDEF  #
#	Octal = 01234567		 #
# -- -- -- -- -- -- -- -- -- #

Donc, on convertie  le octal/hexa vers un int standard.
Puis on appel itoa_base qui vas sortir un char selon le
int et la base.


// %[parameter][flags][width][.precision][length]type


	Length to handle
		

	Type to handle
		sSpdDioOuUxXcC
	
	
	IN											[DONE]
s	char * (String of characters);				OK
S	wchar_t * 									OK
p	void * (Pointer address)					OK
d	Signed decimal integer						OK
i	Signed decimal integer						OK
o	Unsigned octal								OK
u	Unsigned decimal integer					OK
x	Unsigned hexadecimal integer				OK
X	Unsigned hexadecimal integer (uppercase)	OK
c	Character									OK
O	[lo]	Long Unsigned octal					OK
U   [lu]	Long Unsigned decimal integer		OK
D	[ld]	Long Signed decimal integer			OK
C	[lc]	Long (wchart_t) Character			OK








