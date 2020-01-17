##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

VERSION			=		-std=c++17

CXX				=		g++ $(VERSION)

RM				=		rm -f

INCDIRS			=		$(addprefix -I, $(shell find ./include ../../include -type d -print))

CXXFLAGS		=		-Wall -Wextra
CXXFLAGS		+=		$(INCDIRS)

NAME			=		server

SRCS			=		../CreateUDP.cpp 		\
						../UDP.cpp				\
						../Thread.cpp			\
						$(wildcard src/*.cpp) 	\
						./main.cpp

OBJS			=		$(addsuffix .o, $(basename $(SRCS)))

all				:		$(NAME)

$(NAME)			:		$(OBJS)
				@$(CXX) -o $(NAME) $(OBJS)
				@printf "[\033[1;33mBuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'
				@echo -e "\033[36m\n==== \033[36mCOMPLETED\033[36m ====\033[0m"

clean			:
				@$(RM) $(OBJS)
				@printf "[\033[1;31mDeleted_Obj\033[0m] % 30s\n" $(OBJS) | tr ' ' '.'

fclean			:		clean
				@$(RM) $(NAME)
				@printf "[\033[1;31mDeleted_Binary\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re				:		fclean all

%.o				:		%.cpp
				@$(CXX) $(CXXFLAGS) -c -o $@ $<
				@echo -e "[\033[35mCompiled\033[0m]" "---->" $< || echo -e "REALLY NIGGA ??!!" $<

.PHONY			:		all clean fclean re %.o
