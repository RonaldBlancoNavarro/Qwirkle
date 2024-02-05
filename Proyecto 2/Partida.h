#ifndef PARTIDA_H
#define PARTIDA_H
#include<iostream>
#include<graphics.h>
#include"Boton.h"
#include"Cuadro_texto.h"
#include"Jugador.h"
#include"Maquina.h"
#include"Bolsa.h"

#include <cstdio>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;




class Partida
{
	private:
		
		Bolsa bag;
		Jugador player;
		Maquina machine;
		Ficha tablero[13][20];
		int puntajeLimite;

		//puro estetica o botones
		
		
		
		
	public:
		Partida();
		Partida(Bolsa,Jugador,Maquina,int);
		
		void setBag(Bolsa);
		void setPlayer(Jugador);
		void setMachine(Maquina);
		void setTablero(Ficha[][20]);
		void setPuntajeLimite(int);

		
		Bolsa getBag();
		Jugador getPlayer();
		Maquina getMachine();
		int getPuntajeLimite();

		void trasladar(int, int);//traslada ficha de player a tablero
		
		bool guardar();
		
		void jugar();//como parametro le entra el puntaje al que termina la partida y el nombre del jugador		int,char*
		
		void rellenarBarajaJugador();//asigna las fichas al jugador
		
		void rellenarBarajaMaquina();//asigna las fichas a la maquina
		
		
		
		bool autorizar(int,int,char);//autorisa la poscibildad de que una ficha del jugador o maquina se pueda colocar en una cierta posciond del tablero 
		
		
		char seleccionarTurno(char);//seleccionaria el turno al inicio de la partida
		
		
		void int_To_charpuntero(int,int,int);//metodo que hace comversion de tipos y ademas pinta en pantalla lo convertida
		
		int calculadorPuntaje();
		
		
		~Partida();
};
 
#endif
