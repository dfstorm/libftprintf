
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
    %   #   i   .*  hh  sSpdDioOuUxXcC
        0   *   .i  h  
        -           l
        +           ll
                    j
                    z

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
	
	
	IN											[PRE]	[DONE]
s	char * (String of characters);				OK		OK
S	wchar_t * 									OK		OK
p	void * (Pointer address)					OK
d	Signed decimal integer						OK
i	Signed decimal integer						OK
o	Unsigned octal								OK
u	Unsigned decimal integer					OK
x	Unsigned hexadecimal integer				OK
X	Unsigned hexadecimal integer (uppercase)	OK
c	Character									OK		OK
O	[lo]	Long Unsigned octal					OK
U   [lu]	Long Unsigned decimal integer		OK
D	[ld]	Long Signed decimal integer			OK
C	[lc]	Long (wchart_t) Character			OK		OK

Patern diffent si alpha ou num. Donc deux path:

Num:	diouxXOUD
char	sSpcC




Il faut une stratégie d'entré-sortie vue les limitations de la normes.

Pointeur ? Nope. Ca ne change pas le probleme.

Donc, il faut ce faire des fonctions en masse... 
Mais pour les limites: Planification.

Il faut stocker une chaines pour y faire les actions selon les params. On ne peut
pas simplement afficher. Il me semble...




