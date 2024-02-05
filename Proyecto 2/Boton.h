#ifndef BOTON_H
#define BOTON_H
#include<iostream>
#include<graphics.h>
#include"Cuadro_Texto.h"

using namespace std;


class Boton
{
	private:
		int x;	//sus coordenadas funcionan igual que un  boton
		int y;
		int x2;
		int y2;
		bool clickeado;//compruba si el boton fue presionado
		Cuadro_Texto *button;//puede necesitarlo o no 
		
		
	public:
				
		Boton();
		Boton(int,int,int,int,bool,Cuadro_Texto *);
//sets
		void setX(int);
		void setY(int);
		void setX2(int);
		void setY2(int);
		void setClickeado(bool);
		void setButton(Cuadro_Texto*);
//gets		
		int getX();
		int getY();
		int getX2();
		int getY2();	
		bool getClickeado();
		Cuadro_Texto* getButton();
		
		
		void isSobre();//sirve para saber si el puntero esta encima del boton y cambia de color
		bool precionado();//sirve como un cuadro de texto que posee la funcionalidad de un boton 
		bool botonInvisible();//puede hacer que una area de la pantalla funcione como boton aunque no posea nada

		~Boton();
};

#endif
