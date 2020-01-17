##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

COPY = cp -rf ./src/server/server ./src/client/client .

RM = rm -rf server client

all		:
		@printf "\n"
		@$(MAKE) -C ./src/server
		@printf "\n"
		@$(MAKE) -C ./src/client
		@$(COPY)
		@printf "\n[\033[1;35mCalled_Makefiles\033[0m] % 32s\n"
		@echo -e "\033[32m\n==== \033[32mDONE\033[32m ====\033[0m"

clean	:
		@$(MAKE) -C ./src/server clean
		@$(MAKE) -C ./src/client clean
		@printf "\n[\033[1;35mCleaned_Obj_Makefiles\033[0m] % 30s\n"

fclean	:
		@$(MAKE) -C ./src/server fclean
		@$(MAKE) -C ./src/client fclean
		@$(RM)
		@printf "\n[\033[1;35mCleaned_Binary_Obj_Makefiles\033[0m] % 30s\n"

re		:	fclean all

.PHONY	:	all fclean clean re
