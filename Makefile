#g++ -std=c++17 bubble/a.out bubble/bubble.cpp  
all: 
	@echo "Usage: make <program>\nE.g., make bubble"

bubble: 
	ls

# Not working properly
clean:
	rm *.o a.out