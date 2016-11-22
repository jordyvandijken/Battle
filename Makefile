all:
	g++ -c main.cpp -o main.o
	g++ -c person.cpp -o person.o
	g++ -c weapon.cpp -o weapon.o
	g++ -c ak.cpp -o ok.o
	g++ -c awp.cpp -o awp.o
	g++ -c bow.cpp -o bow.o
	g++ -c famas.cpp -o famas.o
	g++ -c fist.cpp -o fist.o
	g++ -c revolver.cpp -o revolver.o
	g++ *.o -o main

run:
	make all
	make cleanbin
	./main

clean:
	rm main *.o

cleanbin:
	rm *.o
