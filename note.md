
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

Tactic de recup des informations:
1- Isoler la chaines de commande.

    Comment détecter la fin de la commande?
    
    Assomptions:
    1- Il n'y a pas d'espace possible dans les params optionnels [FAUX]
    2- La commande doit finir par un flag supporté.
    
    Donc, il faut aussi valider les options possibles et s'assurer
    qu'elle sont valides.
    
    Donc, sur detection du '%'
    
    [parameter]
        // Optionnel pour le projet
        
    [flags]
        [#0-+ ]
        Donc, on cherche a detecter ces chars.
        
    [width]
        [*|[int]]
        * == Un argument en plus est attendu pour avoir le Width
        Puis tant que c'est un nombre ou si c'est un *.
        
    [.precision]
        Determiner par le '.' suivit d'un int ou d,un '*' comme le flag
        float:  (bonnus) Pour reduire le nombre delement, on commence par
                reduire la precision derriere la virgule puis le nombre
                de chiffre afficher.
		int:	Nombre de chiffre minimum a afficher. Si valeur 0 et . 0 => on affiche rien.
        string: On reduit le nombre de char afficher.
        Pour le reste: do noting.

    [length]
        Je ne maitrise pas cette fonctionnalite. Test to do. Je peux quand meme faire la
        validation en massurant que le char est compris.
         hh
         h
         l
         ll
         j
         z
    type
        Char valides:
            sSpdDioOuUxXcC


            
    Donc, Les niveaux:
    0 > 1 > 2 > 3 > 4 > 5
    %   #   i   .i  hh  sSpdDioOuUxXcC
        0   *   .*  h  
        -           l
        +           ll
                    j
                    z

    * = int

    C'est l'ensemble des possibilite. 

    Comment fair pour permettre une "multi-fonction" ++ ?
    
    Solution: prendre le plus haut type de char pour le stockage.
    Probleme: Ce type de char est probablement non-natif ? 

	Pour le fun: Ce faire un mini protocole d'entree sortie ?
	
	Exemple: 
				Une information arrive, on connait son type.
				
				On cree la variablte au bon type type et on y met
				l'information. 
				On cree un objet correspondant a une structure:
					Void (pointeur vers la nouvelle variable);
				
				// // // // // // // // // // // // // // // // // //
				
				Donc, mon objectif: Prendre une string, peu importe
				laquelle
				
				Solution: Liste chainé "char par char" avec le size.
				
				
				
    
	Type to handle
		sSpdDioOuUxXcC
	
	
	IN											[PRE]	[INPUT]	[Fl td]	[Fl done]
s	char * (String of characters);				OK		OK		-		-
S	wchar_t * 									OK		OK		-		-
p	void * (Pointer address)					OK		OK		-		-
d	Signed decimal integer						OK		OK		-_+0	-_+0
i	Signed decimal integer						OK		OK		-_+0	-_+0
o	Unsigned octal								OK		OK		-0#		-0#
u	Unsigned decimal integer					OK		OK		-0		-0
x	Unsigned hexadecimal integer				OK		OK		-0#		-0#
X	Unsigned hexadecimal integer (uppercase)	OK		OK		-0#		-0#
c	Character									OK		OK		-		-
O	[lo]	Long Unsigned octal					OK		OK		-0#		-0#
U   [lu]	Long Unsigned decimal integer		OK		OK		-0		-0
D	[ld]	Long Signed decimal integer			OK		OK		-_+0	-_+0
C	[lc]	Long (wchart_t) Character			OK		OK		-		-

Patern diffent si alpha ou num. Donc deux path:

Num:	diouxXOUD
char	sSpcC


## Lenght
ID	Flags	Types
			d/i				uoxX					c		s
0	none	int				Unsigned Int			int		char*
1	hh		Signed char		Unsigned Char			
2	h		Short Int		Unsigned Short int		
3	l		Long int		Unsigned Long int		wint_t	wchart_t
4	ll		Long Long Int	Unsigned Long Long int
5	j		intmax_t		uintmax_t
6	z		size_t			size_t


Techniquement, les flags de length sont toujours entre ft_strlen(str) - 2 et -1.


dioux

X => ft_strupper(x); Cas special.

O => lo
U => lu
D => ld

Donc, techniquement, je n'ai que "dioux" a gerer.

di = Signed int (10)	di = Signed int (10);
o = Unsigned int (8);	oux	= Unsigned int (8/10/16);
u = Unsigned int (10);	
x = unsigned int (16);

Donc, pour simplifier le tout:

Pour di = Toujours signe et en base 10.

Donc, imaginer une methode "streamlined"...
Probleme 1- itoa is gonna crash on intmax_t ?
	Systeme 64 bit : long long int.
	Donc on pourrait assumer que long long int == Good enought.


	Donc, un lliota et on lluitoa pourrait faire le travail pour tous.

	
DONE ! I DID IT !


Then, memcheck...
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./prog

Yeah ! Juste 4 erreurs !
// ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)
// ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


Je perd 1 byte / block par char de variable afficher. The fuck.

==16110== 1 bytes in 1 blocks are definitely lost in loss record 1 of 1
==16110==    at 0x4C2CB8F: malloc (vg_replace_malloc.c:299)
==16110==    by 0x10ABB3: ft_memalloc (ft_memalloc.c:20)
==16110==    by 0x10A5FB: ft_lstnew (ft_lstnew.c:27)
==16110==    by 0x10A72A: ft_lstfromstr (ft_lstfromstr.c:16)
==16110==    by 0x1091F6: ftpf_string_n (ftpf_strings.c:42)
==16110==    by 0x109357: ftpf_strings (ftpf_strings.c:70)
==16110==    by 0x108EFD: ftpf_types (ftpf_types.c:93)
==16110==    by 0x10882E: ftpf_core (ftpf_core.c:15)
==16110==    by 0x1087BD: ft_printf (ft_printf.c:10)
==16110==    by 0x108706: main (in /home/me/Projets/libftprintf/prog)

ftpf_string_n recupere la string then la met dans une liste via ft_lstfromstr.

Le probleme existe aussi pour les nombres. Passant aussi par ft_lstfromstr.

ft_lstfromstr ajoute un element de liste depuis un char* par char a une liste passer en reference.

Donc on y vas a reverse.

ft_strlen du char recu.
et on fait + 1 puis --x jusqua >= 0 pour chaque char.

Pour chaque char on cree une entree t_list quon ajoute a la t_list principal.

Mon probleme est que je semble faire des blocks trop gros.. ou trop petit... Something's wrong here.

////

Bon, une mauvaise assomption:

Le flag de precisions est a recoder.

Si -1 : On ignore. Si > -1, il y a un flag.

Le pading vas faire chier?

Si jamais le pading est setter, le w sera de 0 et il y aura le prefix.

Le .
Num	 = le minim de chiffre a afficher
Alpha= Le maximum de char a aficher.

Exemples:	%.2s, "abc" = ab
			%3.2s, "abc" = _ab
			%-3.2s, "abc" = ab_
			
			leftpad dont apply to alpha.
			
			Donc si string ou wstring, on fait juste
			ajouter une limitation d<affichage et on
			ajoute la dif au w ?








