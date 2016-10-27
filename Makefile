all:
	g++ -c main.cpp -o main.o
	g++ -c person.cpp -o person.o
	g++ -c weapon.cpp -o weapon.o
	g++ -c ak.cpp -o ak.o
	g++ -c fist.cpp -o fist.o
	g++ *.o -o main


clean:
	rm *.o
