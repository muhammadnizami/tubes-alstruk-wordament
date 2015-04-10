#ifndef mainmenu_h
#define mainmenu_h

#include "ADT Multi List/multilistv5.h"

void mainmenu();
//subrutin main menu

void Register(List * L);

void Login(List * L);

void HowTo();

void About();

void Quit(List * L, boolean * quit);
//I.S. quit true, L terdefinisi
//F.S. quit false, L disimpan ke file eksternal lalu L di memori dihapus

#endif
