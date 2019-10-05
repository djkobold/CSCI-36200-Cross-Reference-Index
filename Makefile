#Daniel Kobold
#CSCI362 PA2
#Makefile

all: index

clean:
	rm index

index: index.hpp index.cpp list.cpp tree.cpp
	g++ -o index index.hpp index.cpp list.cpp tree.cpp
	
debug: index.hpp index.cpp list.cpp tree.cpp
	g++ -g -o index index.hpp index.cpp list.cpp tree.cpp