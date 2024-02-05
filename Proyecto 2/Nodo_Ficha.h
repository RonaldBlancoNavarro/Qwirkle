#ifndef NODO_FICHA_H
#define NODO_FICHA_H
#include<iostream>
#include<graphics.h>
#include"Ficha.h"
using namespace std;

class Nodo_Ficha
{
	private:
		Ficha *pieza;
		Nodo_Ficha *sig;
		
	public:
		Nodo_Ficha();
		Nodo_Ficha(Ficha*,Nodo_Ficha*);	
		void setPieza(Ficha*);
		void setSig(Nodo_Ficha*);
		Nodo_Ficha* getSig();	
		Ficha* getPieza();	
		~Nodo_Ficha();

		string  toString();
};

#endif
