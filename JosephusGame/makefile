# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o destination.o ListmyJosephus.o VectormyJosephus.o 
	g++ -Wall -std=c++11 main.o destination.o ListmyJosephus.o VectormyJosephus.o -o PA2Prog

main.o: main.cpp VectormyJosephus.h ListmyJosephus.h
	g++ -Wall -std=c++11 -c main.cpp 


destination.o: destination.cpp destination.h
	g++ -Wall -std=c++11 -c destination.cpp

ListmyJosephus.o: ListmyJosephus.cpp ListmyJosephus.h
	g++ -Wall -std=c++11 -c ListmyJosephus.cpp

VectormyJosephus.o: VectormyJosephus.cpp VectormyJosephus.h
	g++ -Wall -std=c++11 -c VectormyJosephus.cpp
	


clean: 
	-rm *.o

run:
	@./PA2Prog