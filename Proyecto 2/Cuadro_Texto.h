#ifndef CUADRO_TEXTO_H
#define CUADRO_TEXTO_H
#include<iostream>
#include<graphics.h>
using namespace std;

class Cuadro_Texto
{
	private:
		int x;// los primeros x-y son para una posicion inicial
		int y;
		int x2;//x2 y x3 son para determinar el otro punto que ayuda a delimitar la graficacion del cuadro e texto
		int y2;
		int color;
		int tamanoletra;// 1.2.3   usado para jugar con el tamaño de letra del texto
		char *texto;// puede o no estar presente dentro de boton
		
	public:
		Cuadro_Texto();
		Cuadro_Texto(int,int,int,int,int,int,char*);


//sets
		void setX(int);
		void setY(int);
		void setX2(int);
		void setY2(int);	
		void setColor(int);
		void setTamanoLetra(int);
		void setTexto(char*);
//gets		
		int getX();
		int getY();
		int getX2();
		int getY2();		
		int getColor();
		int getTamanoLetra();
		char* getTexto();



		void dibujar();// metodo que dibuja el cuadro de texto en la pantalla
		void escribir();//metodo que permite al cuadro cambiarle el contenido del texto que este posee

		
		~Cuadro_Texto();
};

#endif
