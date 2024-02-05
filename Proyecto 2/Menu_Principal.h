#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H
#include<iostream>
#include<graphics.h>
#include"Partida.h"
using namespace std;


class Menu_Principal
{
	private:
		Partida qwirkle;
		
	public:
		
		Menu_Principal();
		
		void startgame();
		
		void cargar();
		
		void borrarPartida();
		

		
		
		~Menu_Principal();
};

#endif
