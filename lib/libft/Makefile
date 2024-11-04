NAME = libft.a

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c
SOURCES += ft_isascii.c ft_isprint.c ft_strlen.c
SOURCES += ft_memset.c ft_bzero.c ft_memcpy.c
SOURCES += ft_memmove.c ft_strlcpy.c ft_strlcat.c
SOURCES += ft_toupper.c ft_tolower.c ft_strchr.c
SOURCES += ft_strrchr.c ft_strncmp.c ft_memchr.c
SOURCES += ft_memcmp.c ft_strnstr.c ft_atoi.c
SOURCES += ft_calloc.c ft_strdup.c ft_substr.c
SOURCES += ft_strjoin.c ft_strtrim.c ft_split.c
SOURCES += ft_itoa.c ft_strmapi.c ft_striteri.c
SOURCES += ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c
SOURCES += ft_putnbr_fd.c ft_isspace.c ft_ismeta.c
SOURCES += ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c
SOURCES += ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c
SOURCES += ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MSG1 = @echo "\n42@compile ✔️\nCompiled and now is working! 🚂💨"
MSG2 = @echo "\n42@cleaned ✔️\nWe cleaned the floor and now there's no .o files! 🧹"

$(NAME): $(OBJECTS)
		@ar rcs $(NAME) $(OBJECTS)
		$(MSG1)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

clean:
		@$(RM) $(OBJECTS)

fclean:	clean
		@$(RM) $(NAME)
		$(MSG2)

re:		fclean all

.PHONY : all clean fclean re bonus
