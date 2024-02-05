#include<iostream>
#include<graphics.h>
#include<cstdio>
#include <sstream>
#include <string.h>
#include<stdlib.h>
#include"Menu_Principal.h"
using namespace std;

//dos fichas no pueden apuntar a el mismo puntero

//se puede evitar mil dolores igualando todo en el constructor a NULL	

//un boton puede o no llevar cuadro de texto y este cuadro de texto pude o no llevar texto

//mandar direccion de memoria null no sirve

//se pude pasa de golpe de int a char

int main(){

Menu_Principal mainMenu;
mainMenu.startgame();
	
	return 0;

}
