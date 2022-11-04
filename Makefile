NAME =		ft_containers

COMP =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98

# SRCS =		tests/Vector_test.cpp
# SRCS =		tests/Stack_test.cpp
# SRCS =		tests/Map_test.cpp
# SRCS =		tests/Set_test.cpp
# SRCS =		tests/Time.cpp

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