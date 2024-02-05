#ifndef JUGADOR_H
#define JUGADOR_H
#include<iostream>
#include<graphics.h>
#include"Nodo_Ficha.h"
#include<time.h>
#include<stdlib.h>
using namespace std;

//bolsa --jugador y maquina funcionan parecido en cuanto la lista


class Jugador
{
	private:
		char *nombre;
		int puntaje;
		int cantFichas;
		Nodo_Ficha *primero;
		Nodo_Ficha *actual;
		
		
	public:
		Jugador();
		Jugador(char*,int,int,Nodo_Ficha*,Nodo_Ficha*);

//sets		
		void setNombre(char*);
		void setPuntage(int);
		void setCantFichas(int);
//gets		
		char* getNombre();
		int getPuntaje();
		int getCantFichas();
		Nodo_Ficha* getPrimero();//se obtiene el primer de los nodos de la lista		
	
		
		void insertarPrimero(Ficha*);
		void borrar(Ficha*);
		
		bool manipularDeck(bool);
		
		Ficha retornarSeleccionada();//retorna sacando y eliminado de la lista del jugador una ficha que fue selecionada
		
		string  toString();	//muetra datos del jugador
		
		~Jugador();	
};

#endif
