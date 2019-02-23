LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS = -Wall -Wextra -std=c++17

CPPFLAGS = -ILOLIS2D/inc

SRC = 	LOLIS2D/src/GameManager.cpp \
		LOLIS2D/src/Scene.cpp \
		LOLIS2D/src/GameObject.cpp \
		LOLIS2D/src/Transform.cpp \
		LOLIS2D/src/ColorRenderer.cpp

OBJ = $(SRC:.cpp=.o)

NAME = lolis2D.a

RM = rm -f

all: $(NAME)

$(NAME):
	$(CXX) -c -o $(OBJ) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re