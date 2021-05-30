##
## EPITECH PROJECT, 2019
## nanotekspice
## File description:
## makefile
##

CC	=	g++ -g3

RM	=	rm -f

CFLAGS	=	-Wextra -Wall

NAME	=	 groundhog

SRCS	=	main.cpp 	\
			groundhog.cpp	\
			SFML.cpp	\
			check.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):    $(OBJS)
	g++ -o $(NAME) $(OBJS) $(CFLAGS) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(OBJS)
	find . -type f \( -name "*~" -o -name "#*#" \) -delete

fclean:     clean
	rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re