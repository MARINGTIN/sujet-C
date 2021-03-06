#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <libsx.h>
#include "modele.h"
#include "callback.h"
#include "vue.h"
#include "dictionnaire.h"

/* GUI界面的按钮对应的函数
 * Make the corresponding operation function of each button.
 * "quit" "consonne" "voyelle" "fraude" "jouer"
 * & some functions to ensure that the button works
 */

void quit(Widget w, void *d){
 exit(0);
}

/* Print nine letters in the ZoneSaisie0 */
static void donner(str *d){
  SetLabel(ZoneSaisie0, d->lettres);//print lettre in ZoneSaisie0
}

void consonne(Widget w, void *d){
  tirerConsonne(d);//Randomly generate a consonant letter
  donner(d);//Print the lettre
}

void voyelle(Widget w, void *d){
  tirerVoyelle(d);//Randomly generate a vowel letter
  donner(d);//Print the lettre
}

/* Print the longest word 
 * which is consisting of given letters 
 * which is in the dictionnary 
 * print in the ZoneSaisie6
 * 将最长的单词打印到组件上的函数
 */
static void donner_best(str *d){
  char b[200] = "Le mot le plus long est: ";
  strcat(b, dictionnaire[d->best_count]);
  SetStringEntry(ZoneSaisie6, b);
}

/* This is a cheater button
 * when you click this button, 
 * you will get the longest word!
 * 按下按钮即可获得最长的单词 
 */
void fraude(Widget w, void *d){
  motValide_best(d);
  donner_best(d);
}

/* 对应Jouer按钮，按下即自动比对单词是否符合规范和比较长短 */
void jouer(Widget w, void *d){
  /* Read the words entered by two gamers */
  ((str*) d)->motj1 = GetStringEntry(ZoneSaisie1);
  ((str*) d)->motj2 = GetStringEntry(ZoneSaisie2);
  motValide(d);//judge the words of 2 gamers, and print the final result
}
