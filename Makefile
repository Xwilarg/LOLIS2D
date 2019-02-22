LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS = -Wall -Wextra -std=c++14

CPPFLAGS = -ILOLIS2D/inc

SRC = 	LOLIS2D/main.cpp \
		LOLIS2D/src/GameManager.cpp

NAME = lolis.out

RM = rm -f

all: $(NAME)

$(NAME):
	$(CXX) -o $(NAME) $(SRC) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS)

clean:
	$(RM) $(NAME)

.PHONY: all clean