NAME =		ft_containers

COMP =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98 -g# -fsanitize=address

SRCS =		*.cpp

OBJS =		$(SRCS:%.cpp=%.o)

$(NAME):	$(SRCS)
	$(COMP) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: all clean fclean re