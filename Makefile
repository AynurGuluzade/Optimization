all:
	g++ -g -DDEBUG=2 glad.c visualisation/stb_image.cpp visualisation/render.cpp optimization/optimization.cpp main.cpp optimization/Graph/gl2ps.c optimization/Graph/matplotpp.cpp optimization/Graph/SimpleGraph.cpp -std=c++11 -w -lglfw -ldl -lassimp -lglut -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -o main
