OBJ = obj/main.o  obj/text.o obj/jeu.o  obj/bombe.o  obj/joueur.o  obj/terrain.o obj/adversaire.o 
obj/Wintxt.o 

bin/progt: $(OBJ)
	g++ -o progt $(OBJ) -o $@ 

obj/main.o: src/main.cpp
	g++ -c -Wall src/main.cpp -o $@

obj/text.o: src/text.cpp src/text.h 
	g++ -c -Wall src/text.cpp -o $@ 

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

obj/Wintxt.o: src/Wintxt.cpp src/Wintxt.h
	g++ -c -Wall src/Wintxt.cpp -o  $@

clear:
	rm obj/*.o
