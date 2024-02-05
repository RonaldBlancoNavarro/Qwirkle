#ifndef FICHA_H
#define FICHA_H
#include<iostream>
#include<graphics.h>
#include"Boton.h"
#include<sstream>
using namespace std;


//no decidi crear una herencia entre diferentes tipos de figura 
//pues se estarian creando varias clases que podrian hacer la funcion de un solo metodo

class Ficha
{
	private:
		
		int x;//x--y para posiciones de graficacion
		int y;
		int color;//para definir color
		char figura;//para definir figura
		bool seleccionada;//para definir el echo de que si se encuentra selecionada ---tambien influye en la manera de graficar la ficha

		
	public:
		Ficha();
		
		Ficha(int,int,int,char,bool);
	//sets	
		void setX(int);
		void setY(int);
		void setColor(int);
		void setFigura(char);
		void setSeleccionada(bool);

	//gets	
		int getX();
		int getY();
		int getColor();
		char getFigura();
		bool getSeleccionada();

		

		
		void pintar();//pinta el la ficha
		
	void funcion(int);//elija entre difernetes obciones que puede tener una ficha
	
	string  toString();//muestra datos de la ficha
		
		~Ficha();
};

#endif
