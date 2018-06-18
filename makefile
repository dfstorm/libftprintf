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
str/ft_isprintable.c\
str/ft_llitoa_base.c\
str/ft_lluitoa_base.c\
str/ft_findcis.c\
str/ft_strlenw.c\
str/ft_strfindchar.c\
str/ft_itoa_base.c\
str/ft_uitoa_base.c\
str/ft_luitoa_base.c\
str/ft_litoa_base.c\
str/ft_strupper.c\
mem/ft_bzero.c \
mem/ft_memcpy.c \
mem/ft_memcmp.c \
mem/ft_memset.c \
mem/ft_memalloc.c \
mem/ft_memccpy.c \
mem/ft_memchr.c \
mem/ft_memmove.c \
mem/ft_memdel.c \
mem/ft_memcpy_ref.c \
lst/ft_lstadd.c \
lst/ft_lstdel.c \
lst/ft_lstiter.c \
lst/ft_lstdelone.c \
lst/ft_lstmap.c \
lst/ft_lstnew.c \
lst/ft_lstcount.c\
lst/ft_lstfromstr.c\
lst/ft_lstcpy.c\
lst/ft_lstcutat.c\
lst/ft_lstwipe.c\
out/ft_isprint.c \
out/ft_putchar.c \
out/ft_putchar_fd.c \
out/ft_putendl.c \
out/ft_putendl_fd.c \
out/ft_putnbr.c \
out/ft_putstr_fd.c \
out/ft_putstr.c \
out/ft_putnbr_fd.c\
out/ft_putunbr.c\
out/ft_putlunbr.c\
out/ft_putlsnbr.c\
out/ft_putlstr.c\
out/ft_putlchar.c\
in/get_next_line.c\
printf/ft_printf.c \
printf/ftpf_isolate.c\
printf/ftpf_types.c\
printf/ftpf_strings.c\
printf/ftpf_write.c\
printf/ftpf_numbers.c\
printf/ftpf_utils.c\
printf/ftpf_get_n.c\
printf/ftpf_precision.c


PROJECT = libftprintf
NAME = $(PROJECT).a
CC = gcc
CFLAGS += -g -Wall -Werror -Wextra

SRC_PATH = ./src/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
OBJ_PATHS = out in lst mem str printf


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
	gcc -o testunit main.c libftprintf.a && ./testunit
