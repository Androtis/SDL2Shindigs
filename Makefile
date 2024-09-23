CXXFLAGS=-Wall - pipe -std=c++17

all:
	g++ -I src/include -L src/lib -o program program.cpp -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lglfw3 -lglm 
