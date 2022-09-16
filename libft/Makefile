NAME = libft.a

FSANITIZE = -g3 -fsanitize=address

SRCSPATH = srcs

OBJ_PATH = obj

HEADERS = include \

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
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
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c
		
CC = gcc

CFLAGS = -MMD -Wall -Werror -Wextra

RM = rm -rf

OBJS =  $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

DEPS = $(OBJS:.o=.d)

vpath %.h $(HEADERS)
vpath %.c $(SRCSPATH)\

vpath %.o $(OBJ_PATH)

all: $(NAME)

$(NAME):		$(OBJS)
			ar rcs ${NAME} ${OBJS}

$(OBJ_PATH)/%.o:		%.c
			$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(OBJS):	| $(OBJ_PATH)

$(OBJ_PATH):
			mkdir -p $(OBJ_PATH)

clean:
		${RM} $(OBJ_PATH)

fclean:
		make clean
		${RM} ${NAME}

re:
	make fclean
	make all

-include $(DEPS)

.PHONY:			all clean fclean re