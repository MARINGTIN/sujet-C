#pragma once
#include <libsx.h>

/* 实现所有功能的结构体 */
typedef struct{
  char lettres[9];
  int count;
  char *motj1;
  char *motj2;
  int best_len;
  int best_count;
}str;

extern void tirerVoyelle(str *d);
extern void tirerConsonne(str *d);
extern _Bool motDictionnairej1 (str *d);
extern _Bool motDictionnairej2 (str *d);
extern _Bool motLettresj1 (str *d);
extern _Bool motLettresj2 (str *d);
extern void Jouer(int c1,int c2,int c3,int c4, int l);
extern void motValide(str *d);
extern void motValide_best(str *d);
