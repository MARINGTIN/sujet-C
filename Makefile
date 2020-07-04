CC = gcc # le compilateur à utiliser
CFLAGS = -Wall # les options du compilateur
LDFLAGS = -lsx # les options pour l’éditeur de liens
SRC = main.c callback.c modele.c vue.c # les fichiers sources
PROG = play # nom de l’exécutable
OBJS = $(SRC:.c=.o) # les .o qui en découlent
.SUFFIXES: .c .o # lien entre les suffixes
all: $(PROG)
# étapes de compilation et d’édition de liens
# $@ la cible $^ toutes les dépendances
$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
callbacks.o: callback.h modele.h dictionnaire.h vue.h
modele.o: modele.h vue.h callback.h
main.o: vue.h modele.h callback.h
# le lien entre .o et .c
# $< dernière dépendance
%.o: %.c
	$(CC) $(CFLAGS) -c $<
# pour faire propre
.PHONY: clean
clean:
	rm −f *.o *~ core $(PROG)
