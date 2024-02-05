#ifndef MAQUINA_H
#define MAQUINA_H
#include<iostream>
#include<graphics.h>
#include"Nodo_Ficha.h"
#include<time.h>
#include<stdlib.h>
using namespace std;

//bolsa --jugador y maquina funcionan parecido en cuanto la lista


class Maquina
{
	private:
		int puntaje;
		int cantFichas;
		Nodo_Ficha *primero;
		Nodo_Ficha *actual;
		
	public:
		Maquina();
		Maquina(int,int,Nodo_Ficha*,Nodo_Ficha*);
//sets	
		void setPuntage(int);
		void setCantFichas(int);
//gets
		int getPuntaje();
		int getCantFichas();
		Nodo_Ficha* getPrimero();

		
		void insertarPrimero(Ficha*);
		void borrar(Ficha*);
		
	Ficha retornarSeleccionada();	//retorna una ficha si fue seleccionada	


		string  toString();
		
				~Maquina();	
};

#endif
