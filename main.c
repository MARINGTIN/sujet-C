#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include <time.h>
#include "modele.h"
#include "vue.h"

/*
     Fonction principale
     Main Fonction
*/ 
int main(int argc, char *argv[]) {
  srand ((unsigned int)time(NULL));
  //make sure that initialize the random seed at the current computer time
  str d;
   d.count=0;
   d.best_len=0;//to storage the longest word
   d.best_count=0;//to storage the number of the longest lettre in the dictionnary
   /* to storage 9 letters */
   d.lettres[0]=' ';
   d.lettres[1]=' ';
   d.lettres[2]=' ';
   d.lettres[3]=' ';
   d.lettres[4]=' ';
   d.lettres[5]=' ';
   d.lettres[6]=' ';
   d.lettres[7]=' ';
   d.lettres[8]=' ';
   /* to make the lable empty and without some strang words(terrible) */
   d.lettres[9]=' ';
   d.lettres[10]=' ';
   d.lettres[11]=' ';
  /* to make the window, it's necessary */
  argc = OpenDisplay(argc, argv);
  if(argc == 0){
    fprintf(stderr,"Can’t open display\n");
    return EXIT_FAILURE;
  }  
  init_display(argc, argv, &d);
  MainLoop();
  return EXIT_SUCCESS;
}

 
