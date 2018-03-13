# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 11:34:53 by ggenois      #+#   ##    ##    #+#        #
#    Updated: 2018/03/08 16:17:24 by ggenois     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

C_FILES = str/ft_atoi.c \
str/ft_isalnum.c \
str/ft_isascii.c \
str/ft_isalpha.c \
str/ft_isdigit.c \
str/ft_itoa.c \
str/ft_strclr.c \
str/ft_strchr.c \
str/ft_strcat.c \
str/ft_strdel.c \
str/ft_strcpy.c \
str/ft_strcmp.c \
str/ft_striter.c \
str/ft_striteri.c \
str/ft_strequ.c \
str/ft_strdup.c \
str/ft_strlen.c \
str/ft_strlcat.c \
str/ft_strjoin.c \
str/ft_strmap.c \
str/ft_strncmp.c \
str/ft_strmapi.c \
str/ft_strncat.c \
str/ft_strncpy.c \
str/ft_strnew.c \
str/ft_strnequ.c \
str/ft_strrchr.c \
str/ft_strnstr.c \
str/ft_strsub.c \
str/ft_strstr.c \
str/ft_tolower.c \
str/ft_toupper.c \
str/ft_strtrim.c \
str/ft_strsplit.c \
str/ft_printf.c \
memory/ft_bzero.c \
memory/ft_memcpy.c \
memory/ft_memcmp.c \
memory/ft_memset.c \
memory/ft_memalloc.c \
memory/ft_memccpy.c \
memory/ft_memchr.c \
memory/ft_memmove.c \
memory/ft_memdel.c \
list/ft_lstadd.c \
list/ft_lstdel.c \
list/ft_lstiter.c \
list/ft_lstdelone.c \
list/ft_lstmap.c \
list/ft_lstnew.c \
output/ft_isprint.c \
output/ft_putchar.c \
output/ft_putchar_fd.c \
output/ft_putendl.c \
output/ft_putendl_fd.c \
output/ft_putnbr.c \
output/ft_putstr_fd.c \
output/ft_putstr.c \
output/ft_putnbr_fd.c\
perso/ft_strfindchar.c\
perso/ft_convert_baseten.c\
perso/ft_itoa_base.c\
perso/ft_putunbr.c\
perso/ft_strupper.c\
perso/ft_uitoa_base.c\
perso/ft_putlunbr.c\
perso/ft_putlsnbr.c\
perso/ft_putlstr.c\
perso/ft_putlchar.c

PROJECT = libftprintf
NAME = $(PROJECT).a
CC = gcc
CFLAGS += -g -Wall -Werror -Wextra

SRC_PATH = ./src/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
OBJ_PATHS = output list memory str perso


OBJ_SUB_PATHS = $(addprefix $(OBJ_PATH),$(OBJ_PATHS))
OBJ_NAME = $(C_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(C_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_SUB_PATHS)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@ar -rc $(NAME) $^
	@ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

test: all
	gcc -g -L. -lft -I $(INC_PATH) main/main.c

##	Use the compiled libft : 
##		gcc -L. -lft -I $(INC_PATH) [C_FILES] -o [NAME_OUTPUT]

.PHONY: clean fclean re
