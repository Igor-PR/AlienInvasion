all: exec

# exec: desenhos.o classeDesenho.o classeNave.o classeAlien.o main.o
	# g++ -o exec desenhos.o classeDesenho.o classeNave.o classeAlien.o main.o  -lGLU -lGL -lglut 
exec: desenhos.o  main.o
	g++ -o exec desenhos.o main.o -lGLU -lGL -lglut 

desenhos.o:	desenhos.cpp
	g++ -o desenhos.o -c desenhos.cpp 

# classeDesenho.o: classeDesenho.cpp
# 	g++ -o classeDesenho.o -c classeDesenho.cpp

# classeNave.o: classeNave.cpp
# 	g++ -o classeNave.o -c classeNave.cpp

# classeAlien.o: classeAlien.cpp
# 	g++ -o classeAlien.o -c classeAlien.cpp		

main.o: main.cpp desenhos.h classeDesenho.h
	g++ -o main.o -c main.cpp 

clean:
	rm -rf *.o
	
remove:
	rm -rf exec

