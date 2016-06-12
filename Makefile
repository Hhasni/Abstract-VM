
NAME =		AbstractVM

CPATH =		./

SRCS =		main.cpp \
			IntHeight.cpp \
			Int16.cpp \
			Int32.cpp \
			Float.cpp \
			Double.cpp \
			Factory.cpp \
			VM.cpp			


OBJS =		$(SRCS:%.cpp=%.o)

CC =		clang++

CFLAGS =	-Wall -Wextra -Werror -std=c++11

RM =		rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n\r\033[38;5;11m⌛  MAKE $(NAME) plz wait...\033[0m\033[K"
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo -en "\r\033[38;5;22m✅  MAKE $(NAME)\033[0m\033[K"
			@echo "💟"

%.o:		$(CPATH)%.cpp
			@$(CC) $(CFLAGS) -c $<

clean:
			@$(RM) $(OBJS)
			@echo -en "\r\033[38;5;124m❌  CLEAN $(NAME) \033[0m\033[K"

fclean:		clean
			@$(RM) $(NAME)
			@echo -en "\r\033[38;5;124m❌  FCLEAN $(NAME) \033[0m\033[K"

re:			fclean all