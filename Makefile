NAME = libasm.a

SRCS = srcs/ft_strlen.s \
	   srcs/ft_strcpy.s \
	   srcs/ft_strcmp.s \
	   srcs/ft_write.s \
	   srcs/ft_read.s \
	   srcs/ft_strdup.s

OBJS = $(SRCS:.s=.o)

NASM = nasm
NASMFLAGS = -f elf64

AR = ar
ARFLAGS = rcs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.s
	$(NASM) $(NASMFLAGS) -o $@ $<

exec:
	touch mock-write.txt mock-ftwrite.txt
	chmod 0644 mock-write.txt mock-ftwrite.txt
	gcc -o test main.c -L. -lasm && ./test

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf test

re: fclean all
