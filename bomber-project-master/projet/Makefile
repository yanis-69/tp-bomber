OBJ = obj/main.o  obj/affiche.o obj/jeu.o obj/bombe.o obj/joueur.o obj/terrain.o obj/adversaire.o obj/Timer.o

bin/prog: $(OBJ)
	g++ -o prog $(OBJ) -o $@ -I include -L lib -lSDL2main -lSDL2

obj/main.o: src/main.cpp
	g++ -c -Wall src/main.cpp -o $@


obj/affiche.o: src/affich.cpp src/affiche.h 
	g++ -c -Wall src/affich.cpp -o $@ -I include -L lib -lSDL2main -lSDL2

obj/jeu.o: src/jeu.cpp src/jeu.h
	g++ -c -Wall src/jeu.cpp -o $@

obj/adversaire.o: src/Adversaire.cpp src/Adversaire.h
	g++ -c -Wall src/Adversaire.cpp -o $@

obj/bombe.o: src/bombe.cpp src/bombe.h
	g++ -c -Wall src/bombe.cpp -o $@

obj/joueur.o: src/joueur.cpp src/joueur.h
	g++ -c -Wall src/joueur.cpp -o $@

obj/terrain.o: src/terrain.cpp src/terrain.h
	g++ -c -Wall src/terrain.cpp -o  $@

obj/Timer.o: src/Timer.cpp src/Timer.h
	g++ -c -Wall src/Timer.cpp -o  $@
clear:
	rm obj/*.o
