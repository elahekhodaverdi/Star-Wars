CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: starwars.out

starwars.out: main.o game.o spaceship.o enemy.o bullet.o object.o rsdl.o player.o enemies.o hostages.o
	$(CC) main.o game.o spaceship.o enemy.o bullet.o object.o rsdl.o player.o enemies.o hostages.o $(CCFLAGS) -o starwars.out

main.o: game.hpp  rsdl.hpp main.cpp
	$(CC) -c main.cpp -o main.o

game.o: game.hpp spaceship.hpp enemy.hpp bullet.hpp player.hpp enemies.hpp map.hpp hostages.hpp object.hpp rsdl.hpp rectangle_s.hpp defines.hpp game.cpp
	$(CC) -c game.cpp -o game.o

spaceship.o: spaceship.hpp bullet.hpp object.hpp rsdl.hpp rectangle_s.hpp defines.hpp spaceship.cpp
	$(CC) -c spaceship.cpp -o spaceship.o

hostages.o: hostages.hpp enemy.hpp bullet.hpp player.hpp object.hpp rsdl.hpp rectangle_s.hpp defines.hpp hostages.cpp
	$(CC) -c hostages.cpp -o hostages.o

enemy.o: enemy.hpp spaceship.hpp bullet.hpp object.hpp rsdl.hpp rectangle_s.hpp defines.hpp enemy.cpp
	$(CC) -c enemy.cpp -o enemy.o

player.o: player.hpp spaceship.hpp bullet.hpp object.hpp rsdl.hpp rectangle_s.hpp defines.hpp player.cpp
	$(CC) -c player.cpp -o player.o

enemies.o: enemies.hpp spaceship.hpp player.hpp enemy.hpp bullet.hpp object.hpp rsdl.hpp rectangle_s.hpp defines.hpp enemies.cpp
	$(CC) -c enemies.cpp -o enemies.o

bullet.o: bullet.hpp object.hpp rsdl.hpp rectangle_s.hpp defines.hpp bullet.cpp
	$(CC) -c bullet.cpp -o bullet.o

object.o: object.hpp rsdl.hpp rectangle_s.hpp object.cpp
	$(CC) -c object.cpp -o object.o



.PHONY: clean
clean:
	rm -r *.o

