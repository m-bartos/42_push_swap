NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isdigit.c \
			ft_memmove.c \
			ft_strlen.c \
			ft_isprint.c \
			ft_memset.c \
			ft_strncmp.c \
			ft_isalnum.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strnstr.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_isascii.c \
			ft_memcpy.c \
			ft_strlcpy.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			\
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			\
			ft_printf.c \
			ft_putchar_c.c \
			ft_puthexa.c \
			ft_putnbr_c.c \
			ft_putpointer.c \
			ft_putstr_c.c \
			ft_putunsnbr.c \
			ft_type_choose.c\
			\
			get_next_line.c \

OBJ_DIR = ./obj

MY_OBJECTS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SOURCES))

all:	$(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re