#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsx.h>
#include "modele.h"
#include "vue.h"
#include "callback.h"

extern char *dictionnaire[75];

void tirerVoyelle(str *d){
  if( d->count >= 9) return;//if click button more than 9 times it will do nothing
  char tV[46]="aaaaaaaaaeeeeeeeeeeeeeeeiiiiiiiioooooouuuuuuy";
  d->lettres[d->count] = tV[(unsigned int)( 45*(double)rand()/RAND_MAX)];
  d->count++;
  //Générer un nombre aléatoire, renvoyer directement un caractère d'une chaîne de voyelles.
}

void tirerConsonne(str *d){
  if( d->count >= 9) return;
  char tC[56]="bbccdddffgghhjklllllmmmnnnnnnppqrrrrrrssssssttttttvvwxz";
  d->lettres[ d->count] = tC[(unsigned int)( 45*(double)rand()/RAND_MAX)];
  d->count++;
  //Générer un nombre aléatoire, renvoyer directement un caractère d'une chaîne de consonnes.
}

_Bool motDictionnairej1 (str *d){
  int a;
  for (a=0; a<=74; a++) {
    if (strcmp(d->motj1, dictionnaire[a]) == 0)
      break;
  }
  if (a <= 74)
    return 1;
  else if (a == 75)
    return 0;
  else
    return EXIT_FAILURE;
}

_Bool motDictionnairej2 (str *d){
  int a;
  for (a=0; a<=74; a++) {
    if (strcmp(d->motj2, dictionnaire[a]) == 0)
      break;
  }
  if (a <= 74)
    return 1;
  else if (a == 75)
    return 0;
  else
    return EXIT_FAILURE;
}

_Bool motLettresj1 (str *d){
  int m=1;
  for(char i='a'; i<='z'; i++){
    int s=0;
    for(int j=0; j<9; j++){
      if(i == d->lettres[j]) s=1;
    }
    if(s == 1) continue;
    else{
      char *ret=strchr(d->motj1, i);
      if(ret != NULL){
	m=0;
	break;
      }
    }
  }
  return m;
}

_Bool motLettresj2 (str *d){
  int m=1;
  for(char i='a';i<='z';i++){
    int s=0;
    for(int j=0;j<9;j++){
      if(i==d->lettres[j]) s=1;
    }
    if(s == 1) continue;
    else{
      char *ret=strchr(d->motj2, i);
      if(ret != NULL) {
	m=0;
	break;
      }
    }
  }
  return m;
}


/*Les fonctions "Jouer" et "motValide" sont ensemble pour juger le mot que les joueurs donnent.*/
void Jouer(int c1,int c2,int c3,int c4, int l) {
  const int TailleZoneSaisie = TextWidth(GetWidgetFont(ZoneSaisie3), GetStringEntry(ZoneSaisie3));
  if (c1 == 0 || c3 == 0) {
    if (c2 != 0 && c4 != 0){
      char s[TailleZoneSaisie+1];
      sprintf( s, "%s", "Le joueur 2 a gagné,"
	     " le mot du joueur 1 est incorrect.");
      SetStringEntry(ZoneSaisie3, s);
    }
    else if (c2 == 0 || c4 == 0){
      char s[TailleZoneSaisie+1];
      sprintf( s, "%s", "Personne ne gagne,"
	     " les mots des joueurs sont incorrects.");
      SetStringEntry(ZoneSaisie3, s);
    }
  }
  if (c1 != 0 && c3 != 0 ) {
    if (c2 != 0 && c4 != 0) {
      if (l>0){
	char s[TailleZoneSaisie+1];
	sprintf( s, "%s", "Le joueur 1 a gagné,"
	       " son mot est le plus long.");
	SetStringEntry(ZoneSaisie3, s);
      }
      else if (l == 0){
	char s[TailleZoneSaisie+1];
	sprintf( s, "%s", "Match nul! Fin du jeu.");
	SetStringEntry(ZoneSaisie3, s);
      }
      else if (l<0){
	char s[TailleZoneSaisie+1];
	sprintf( s, "%s", "Le joueur 2 a gagné,"
	       " son mot est le plus long.");
	SetStringEntry(ZoneSaisie3, s);
      }
    }
    else if (c2 == 0 || c4 == 0){
      char s[TailleZoneSaisie+1];
      sprintf( s, "%s", "Le joueur 1 a gagné,"
	     " le mot du joueur 2 est incorrect.");
      SetStringEntry(ZoneSaisie3, s);
    }
  }
}

 /*
  *Utilisez plusieurs fonctions pour déterminer si le mot d'entrée répond aux spécifications 
  *Et déterminer le gagnant.
  */
void motValide(str *d){
  int c1, c2, c3, c4;
  int longueurj1 = strlen(d->motj1), longueurj2 = strlen(d->motj2);
  int l = longueurj1-longueurj2;
  /*
   *Les variables représentent des paramètres intermédiaires.
   *c1/2 représente le résultat de comparaison mot entré par joueur1/2 et le dictionnaire.
   *c3/4 représente le résultat de comparaison lettres de mot entré par joueur1/2 
    et les lettres données.
   *Par Variable <<_Bool>>, "1 , 0",
    nous pouvons juger de la situation gagnante en comparant si elle répond aux spécifications.
   */
  c1 = motDictionnairej1 (d);
  c2 = motDictionnairej2 (d);
  c3 = motLettresj1 (d);
  c4 = motLettresj2 (d);
  Jouer(c1, c2, c3, c4, l);
}

void motValide_best(str *d){
  int res;
  int c=0;
  for(c=0; c <= 76; c++){
    res=0;
    for(char i='a';i<='z'; i++){
      int statut=0;
      for(int j=0; j<9; j++){
	if(i == d->lettres[j]) statut=1;
      }
      if(statut == 1) continue;
      else{
        char *ret=strchr(dictionnaire[c], i); 
        if(ret != NULL){
	  res=1;
	  break;
        }
      }
    }
    if(res == 0){
      if(d->best_len < strlen(dictionnaire[c])){
	d->best_len = strlen(dictionnaire[c]);
	d->best_count = c;
      }
    }
  }
}
