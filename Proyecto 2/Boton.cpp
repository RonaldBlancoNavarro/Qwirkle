#include "Boton.h"

Boton::Boton()
{
	x=0;
	y=0;
	x2=0;
	y2=0;
	clickeado=0;;
	button=NULL;
}

Boton::Boton(int x,int y,int x2,int y2,bool cl,Cuadro_Texto *b){
	this->x=x;
	this->y=y;
	this->x2=x2;
	this->y2=y2;
	clickeado=cl;
	button=b;
}
//sets
void Boton::setX(int x){
	this->x=x;
}
void Boton::setY(int y){
	this->y=y;
}

void Boton::setX2(int x2){
	this->x2=x2;
}
void Boton::setY2(int y2){
	this->y2=y2;
}
void Boton::setClickeado(bool cl){
	clickeado=cl;
}
void Boton::setButton(Cuadro_Texto *b){
	button=b;
}
//gets
int Boton::getX(){
	return x;
}
int Boton::getY(){
	return y;
}
int Boton::getX2(){
	return x2;
}
int Boton::getY2(){
	return y2;
}
bool Boton::getClickeado(){
	return clickeado;
}
Cuadro_Texto* Boton::getButton(){
	return button;
}

void Boton::isSobre(){
	
	if(button!=NULL){//cuadro de texto bisible
		
	if(mousex()>getX()&&mousex()<getX2()&&mousey()>getY()&&mousey()<getY2()){//si boton no es nulo y esta encima el cursor asigna un cierto color
	button->setColor(RED);
	}
	else{
	button->setColor(button->getColor());
	}	
		
	}
	
}



bool Boton::precionado(){// se usaria botones normales y en la mesa para detectar 
	
int col=button->getColor();//guardo color antes de imprimir

isSobre();//asigno color segun pos raton


if(button!=NULL){// si hay boton con cuadro texto dibujo
	
	button->dibujar();
	
}

button->setColor(col);//vuelve a color originar

if(mousex()>getX()&&mousex()<getX2()&&mousey()>getY()&&mousey()<getY2()&&ismouseclick(WM_LBUTTONDOWN)){//revisa si se clickeo
	clearmouseclick(WM_LBUTTONDOWN);
	
	setClickeado(true);
	return 1;
}
else{
	setClickeado(false);
	return 0;
}
}





bool Boton::botonInvisible(){// se usaria en lista de jugador en el momento de seleccionar una sierta ficha
	
	if(button==NULL){// que si no se va a pintar un boton;
		
		if(mousex()>getX()&&mousex()<getX2()&&mousey()>getY()&&mousey()<getY2()&&ismouseclick(WM_LBUTTONDOWN)){//revisa si se clickeo
			clearmouseclick(WM_LBUTTONDOWN);
			setClickeado(true);
			return 1;
		}
		else{
			setClickeado(false);	
			return 0;
		}	
		
		}
}



Boton::~Boton()
{
}
