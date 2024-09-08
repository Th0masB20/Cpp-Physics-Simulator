all: run

run: main.cpp ./CppFiles/*.cpp	
	g++ -g -Wall -Werror -fsanitize=address,undefined -std=c++17 -IhFiles ./CppFiles/*.cpp main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

deploy: main
	./main
