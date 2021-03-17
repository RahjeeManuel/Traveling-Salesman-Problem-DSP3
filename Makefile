#builds dsp3.exe
all: dsp3.exe

dsp3.exe: main.o InputHandler.o DistMatrix.o BruteAlg.o GeneticAlg.o
	g++ -o dsp3.exe main.o InputHandler.o DistMatrix.o BruteAlg.o GeneticAlg.o

main.o: main.cpp
	g++ -c main.cpp

InputHandler.o: InputHandler.hpp InputHandler.cpp
	g++ -c InputHandler.cpp

DistMatrix.o: DistMatrix.hpp DistMatrix.cpp
	g++ -c DistMatrix.cpp

BruteAlg.o: BruteAlg.hpp BruteAlg.cpp
	g++ -c BruteAlg.cpp

GeneticAlg.o: GeneticAlg.hpp GeneticAlg.cpp
	g++ -c GeneticAlg.cpp

clean:
	rm *.o dsp3.exe