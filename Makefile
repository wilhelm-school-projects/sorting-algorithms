#g++ -std=c++17 bubble/a.out bubble/bubble.cpp  
#@echo "Usage: make <program>\nE.g., make bubble"
all: bubble quick 
	


bubble: bubble/bubble.o 
	g++ -std=c++17 -o bubble/a.out bubble/bubble.cpp

quick: quick/quick.o 
	g++ -std=c++17 -o quick/a.out quick/quick.cpp

# Not working properly
clean:
	rm -f */*.o a.out