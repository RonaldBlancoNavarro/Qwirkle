#include "Cuadro_Texto.h"

Cuadro_Texto::Cuadro_Texto()
{
	x=0;
	y=0;
	x2=0;
	y2=0;
	color=0;
	tamanoletra=1;
	texto=(char*)"";
}

Cuadro_Texto::Cuadro_Texto(int x,int y,int x2,int y2,int c,int tl,char *t){
	this->x=x;
	this->y=y;
	this->x2=x2;
	this->y2=y2;
	color=c;
	tamanoletra=tl;
	texto=t;
}

//sets
void Cuadro_Texto::setX(int x){
	this->x=x;
}
void Cuadro_Texto::setY(int y){
	this->y=y;
}

void Cuadro_Texto::setX2(int x2){
	this->x2=x2;
}
void Cuadro_Texto::setY2(int y2){
	this->y2=y2;
}

void Cuadro_Texto::setColor(int c){
	color=c;
}
void Cuadro_Texto::setTamanoLetra(int tl){
	tamanoletra=tl;
}

void Cuadro_Texto::setTexto(char* t){
	texto=t;
}

//gets
int Cuadro_Texto::getX(){
	return x;
}
int Cuadro_Texto::getY(){
	return y;
}
int Cuadro_Texto::getX2(){
	return x2;
}
int Cuadro_Texto::getY2(){
	return y2;
}
int Cuadro_Texto::getColor(){
	return color;
}
int Cuadro_Texto::getTamanoLetra(){
	return tamanoletra;
}

char* Cuadro_Texto::getTexto(){
	return texto;
}


void Cuadro_Texto::dibujar(){//metodo de dibuja de cuadro texto
	
	setcolor(getColor()); //primero el cuadro despues el texto
	setfillstyle(SOLID_FILL,getColor());
	bar(getX(),getY(),getX2(),getY2());
	setcolor(0);
	
	settextstyle(8,0,getTamanoLetra());// 1 pequeño 2 mediano 3 grande en cuanto tamaño de letra
	setcolor(WHITE);//con este se le da el color a las letras
	setbkcolor(getColor());
	outtextxy(getX()+10, ((getY2()-getY())/3)+getY(), getTexto());// graficado de texto
	
	setcolor(0);

}

void Cuadro_Texto::escribir(){// este metodo fue explicado rapidame por mi ex tutor de verano keilor, del cual no me acuerdo los apellidos
								//pero fue editado por mi persona gracias
	string pal="";
	char tecla;
	int cont=0;
	do{//entra en un ciclo que se detiene con precionar la tecla intro
		tecla=getch(); //obtiene o guarda un caracter a la vez
		if(tecla>=32&&tecla<=126 ){//aqui recive el caracter
			if(cont<10){
			pal+=tecla;
			settextstyle(8,0,getTamanoLetra());
			setcolor(BLACK);
			setbkcolor(color);
			outtextxy(x+10+textwidth(texto)+textwidth((char*)":"), ((getY2()-getY())/3)+getY(),(char*)pal.c_str());//y+10
			cont++;	
			}
			
		}
		else{
			if(tecla==8&&cont>0){//esta area se usa cuando se borra caracter
				pal.erase(pal.length()-1);
				dibujar();
				settextstyle(8,0,getTamanoLetra());
				setcolor(BLACK);
				setbkcolor(color);
				outtextxy(x+10+textwidth(texto)+textwidth((char*)":"), ((getY2()-getY())/3)+getY(),(char*)pal.c_str());//y+10
				cont--;
			}
		}
	}while(tecla != 13||cont==0);
	texto= (char*)pal.c_str();
	
}

Cuadro_Texto::~Cuadro_Texto()
{
}
