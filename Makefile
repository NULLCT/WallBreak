CXXFLAG=-std=c++17
SFMLFLAG=-lsfml-graphics -lsfml-window -lsfml-system

sfmlapp: main.o wall.o ball.o paddle.o
	clang++ main.o wall.o ball.o paddle.o -o sfmlapp $(CXXFLAG) $(SFMLFLAG)

main.o:main.cpp
	clang++ -c main.cpp -o main.o $(CXXFLAG)
wall.o:wall.cpp
	clang++ -c wall.cpp -o wall.o $(CXXFLAG)
ball.o:ball.cpp
	clang++ -c ball.cpp -o ball.o $(CXXFLAG)
paddle.o:paddle.cpp
	clang++ -c paddle.cpp -o paddle.o $(CXXFLAG)

clean:
	rm *.o
	rm sfmlapp
