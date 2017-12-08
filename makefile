all: exec

exec: funcoes.o  main.o
	g++ -o exec funcoes.o main.o -lGLU -lGL -lglut 

funcoes.o:	funcoes.cpp  classeDesenho.h
	g++ -o funcoes.o -c funcoes.cpp -lGLU -lGL -lglut 

main.o: main.cpp classeDesenho.h funcoes.h
	g++ -o main.o -c main.cpp

clean:
	rm -rf *.o
	
remove:
	rm -rf exec

