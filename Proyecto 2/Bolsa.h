#ifndef BOLSA_H
#define BOLSA_H
#include<iostream>
#include<graphics.h>
#include"Nodo_Ficha.h"
#include<time.h>
#include<stdlib.h>
using namespace std;

//bolsa --jugador y maquina funcionan parecido en cuanto la lista

class Bolsa
{
	private:
		Nodo_Ficha *primero;
		Nodo_Ficha *actual;
		int cantFichas;
	public:
		Bolsa();
		Bolsa(Nodo_Ficha*,Nodo_Ficha*,int);
//sets
		void setCantFichas(int);
		void insertarPrimero(Ficha*);
		void borrar(Ficha*);
	
		Ficha seleccionarAleatoria();//saca un ficha aletorea de la bolsa y de paso la elimina de esta
		
		void rellenarLista();//rellena la lista de 108 fichas siguinedo las reglas
		void contador();//lleva la contabilidad de las fichas cuando se carga la partida --incompleto


//gets	
		int getCantFichas();
		Nodo_Ficha* getPrimero();
		
		string  toString();//muetra todos los datos de las fichas actuales de la bolsa pero en consola
		
		~Bolsa();
};

#endif
