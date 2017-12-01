all: exec

exec: desenhos.o main.o
	g++ -o exec desenhos.o main.o -lGLU -lGL -lglut 

desenhos.o:	desenhos.cpp
	g++ -o desenhos.o -c desenhos.cpp 

main.o: main.cpp desenhos.h
	g++ -o main.o -c main.cpp 

clean:
	rm -rf *.o
	
remove:
	rm -rf exec

