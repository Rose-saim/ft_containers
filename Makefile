SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

CPP	= c++
RM	= rm -f
CFLAGS	= -std=c++98 -Wall -Wextra -Werror

NAME = containers

all: 	$(NAME)

$(NAME):	$(OBJS)
			$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
