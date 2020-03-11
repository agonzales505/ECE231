FNS = complex_fns.cpp
MAIN = main.cpp $(FNS)
all:
	g++ $(MAIN) -o complex
clean:
	rm complex
