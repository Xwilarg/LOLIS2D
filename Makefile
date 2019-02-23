LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS = -Wall -Wextra -std=c++17

CPPFLAGS = -ILOLIS2D/inc

SRC = 	LOLIS2D/main.cpp \
		LOLIS2D/src/GameManager.cpp \
		LOLIS2D/src/Scene.cpp \
		LOLIS2D/src/GameObject.cpp \
		LOLIS2D/src/Transform.cpp \
		LOLIS2D/src/ColorRenderer.cpp

NAME = lolis.out

RM = rm -f

all: $(NAME)

$(NAME):
	$(CXX) -o $(NAME) $(SRC) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS)

clean:
	$(RM) $(NAME)

.PHONY: all clean