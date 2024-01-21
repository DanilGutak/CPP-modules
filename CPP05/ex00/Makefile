NAME		=	fixed
CXX			=	c++
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC			=	Bureaucrat.cpp main.cpp


OBJ_DIR		=	./obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))


DEPS		=	$(SRC:.cpp=.d)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(OBJ) $(FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) 
			$(CXX) $(FLAGS) -c $< -o $@ 

$(OBJ_DIR):
			mkdir -p $@

clean:		
			rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
