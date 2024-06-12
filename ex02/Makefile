CPP		 =	c++
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

OBJ_DIR  =	./objs

NAME	 =	PmergeMe
SRC		 =	main.cpp
OBJ		 =	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | ${OBJ_DIR}
	$(CPP) $(CPPFLAGS) -c $< -o $@

${OBJ_DIR} :
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re