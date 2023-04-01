NAME = libasm.a

SRCS = srcs/ft_strlen.s \
	   srcs/ft_strcpy.s \
	   srcs/ft_strcmp.s \
	   srcs/ft_write.s \
	   srcs/ft_read.s \
	   srcs/ft_strdup.s

OBJS = $(SRCS:.s=.o)

NASM = NASM
NASMFLAGS = -f elf64

AR = ar
ARFLAGS = rcs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.s
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
