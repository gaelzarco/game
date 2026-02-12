game: game.cxx
	g++ game.cxx -std=c++23 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o game

clean:
	rm game
