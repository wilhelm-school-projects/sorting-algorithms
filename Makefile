
all: 
	@echo "Usage: make <program>\nE.g., make bubble"

bubble: 
	g++ -std=c++17 -o bubble/bubble bubble/bubble.cpp  

# Not working properly
clean:
	rm *.o a.out