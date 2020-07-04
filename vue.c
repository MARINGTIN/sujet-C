#include <stdio.h>
#include <stdlib.h>
#include "modele.h"
#include <libsx.h>
#include "callback.h"
#define TAULLEZONESAISIE0  300
#define TAULLEZONESAISIE1  400

Widget ZoneSaisie0;
Widget ZoneSaisie1;
Widget ZoneSaisie2;
Widget ZoneSaisie3;
Widget ZoneSaisie4;
Widget ZoneSaisie5;
Widget ZoneSaisie6;

void init_display( int argc, char *argv[], void *d){

  Widget BQuit, BJouer, BConsonne, BVoyelle, BFraude;//make the buttons
  BQuit     = MakeButton("   Quit   ",     quit,   NULL);
  BJouer    = MakeButton("   Jouer   ",    jouer,    d);
  BConsonne = MakeButton("   Consonne   ", consonne, d);
  BVoyelle  = MakeButton("   Voyelle    ", voyelle,  d);
  BFraude   = MakeButton("  Fraude   ", fraude,   d);
  
  ZoneSaisie0 = MakeLabel("- - - - - - - - -");
  ZoneSaisie1 = MakeStringEntry( NULL, TAULLEZONESAISIE0, NULL, NULL);
  ZoneSaisie2 = MakeStringEntry( NULL, TAULLEZONESAISIE0, NULL, NULL);
  ZoneSaisie3 = MakeStringEntry( NULL, TAULLEZONESAISIE1, NULL, NULL);
  ZoneSaisie4 = MakeLabel("Mot joueur 1 :");
  ZoneSaisie5 = MakeLabel("Mot joueur 2 :");
  ZoneSaisie6 = MakeStringEntry( NULL, TAULLEZONESAISIE1, NULL, NULL);
  
  /*
   * Here, the fonctions are written for make the rgb color
   * & set the background color of the buttons and the lable
   * & set the frontground color(such as the text) of the buttons and the lable.
   */
  int color_0 = GetRGBColor( 255, 149, 150);//pink
  int color_1 = GetRGBColor( 161, 170, 223);//purple
  int color_2 = GetRGBColor(  64, 158, 215);//blue
  int color_3 = GetRGBColor( 248, 246, 233);//beige
  int color_4 = GetRGBColor(   0,   0,   0);//black
  SetBgColor( BQuit,       color_1);
  SetBgColor( BFraude,     color_4);
  SetFgColor( BFraude,     color_3);
  SetBgColor( BJouer,      color_0);
  SetBgColor( BConsonne,   color_2);
  SetBgColor( BVoyelle,    color_2);
  SetBgColor( ZoneSaisie0, color_3);
  SetBgColor( ZoneSaisie1, color_3);
  SetBgColor( ZoneSaisie2, color_3);
  SetBgColor( ZoneSaisie3, color_3);
  SetBgColor( ZoneSaisie4, color_3);
  SetBgColor( ZoneSaisie5, color_3);
  SetBgColor( ZoneSaisie6, color_4);
  SetFgColor( ZoneSaisie6, color_3);
  /*
   *Use this function to determine the relative position of the components
   *To determine the overall layout of the interface
   */
  SetWidgetPos( ZoneSaisie0, PLACE_RIGHT, BConsonne,   PLACE_RIGHT, BVoyelle);
  SetWidgetPos( BVoyelle,    PLACE_UNDER, BConsonne,   NO_CARE,     NULL);
  SetWidgetPos( ZoneSaisie1, PLACE_UNDER, BVoyelle,    PLACE_RIGHT, ZoneSaisie4);
  SetWidgetPos( ZoneSaisie2, PLACE_UNDER, ZoneSaisie1, PLACE_RIGHT, ZoneSaisie5);
  SetWidgetPos( ZoneSaisie4, PLACE_UNDER, BVoyelle,    NO_CARE,     NULL);
  SetWidgetPos( ZoneSaisie5, PLACE_UNDER, ZoneSaisie4, NO_CARE,     NULL);
  SetWidgetPos( BJouer,      PLACE_UNDER, ZoneSaisie5, NO_CARE,     NULL);
  SetWidgetPos( ZoneSaisie3, PLACE_UNDER, BJouer,      NO_CARE,     NULL);
  SetWidgetPos( BQuit,       PLACE_RIGHT, ZoneSaisie3, PLACE_UNDER, BJouer);
  SetWidgetPos( BFraude,     PLACE_RIGHT, BJouer,      PLACE_UNDER, ZoneSaisie5);
  SetWidgetPos( ZoneSaisie6, PLACE_UNDER, ZoneSaisie3, NO_CARE,     NULL);
  
  ShowDisplay();//Functions necessary to form the interface
}
