#include "Ficha.h"

Ficha::Ficha()
{
	x=0;
	y=0;
	color=0;
	figura='*';

	seleccionada=0;


}

Ficha::Ficha(int x,int y,int c,char f,bool sl){//bool v  ,Ficha *a
	this->x=x;
	this->y=y;
	color=c;
	figura=f;

	seleccionada=sl;

}
//sets
void Ficha::setX(int x){
	this->x=x;
}
void Ficha::setY(int y){
	this->y=y;
}
void Ficha::setColor(int c){
	color=c;
}
void Ficha::setFigura(char f){
	figura=f;
}

void Ficha::setSeleccionada(bool s){
	seleccionada=s;
}

//gets
int Ficha::getX(){
	return x;
}
int Ficha::getY(){
	return y;
}
int Ficha::getColor(){
	return color;
}
char Ficha::getFigura(){
	return figura;
}

bool Ficha::getSeleccionada(){
	return seleccionada;
}


void Ficha::pintar(){

	
	//revisa si esta seleccionada
	if(getSeleccionada()==true){
	setfillstyle(XHATCH_FILL,0);//.....si se preciona poner de este rellenado 
	}else{
	setfillstyle(SOLID_FILL,0);//negro  
	}

	
	
	bar(getX()+1,getY()+1,getX()+40-1,getY()+40-1);//dibuja cuadro ficha tamaño total de la ficha   40x40 pero en graficad 39x39
	
	switch( getFigura() ){
	
		case'*':{//nada
			
			break;
		}
		
		case'c':{//circulo
		
		int radio=15;
			
			
		setcolor(getColor());
		setfillstyle(SOLID_FILL,getColor());
		fillellipse(getX()+20,getY()+20,radio,radio);
		setcolor(0);
			
			break;
		}
		
		case'r':{//rombo
		
		setcolor(getColor());
		line(getX()+20,getY()+5,getX()+5,getY()+20);
		line(getX()+20,getY()+5,getX()+35,getY()+20);
		line(getX()+5,getY()+20,getX()+20,getY()+35);
		line(getX()+35,getY()+20,getX()+19,getY()+35);
		setfillstyle(SOLID_FILL,getColor());
		floodfill(getX()+20,getY()+20,getColor());
		setcolor(0);
		
			break;
		}
		
		case's':{//cuadrado ----s de  square
				
		setcolor(getColor());
		setfillstyle(SOLID_FILL,getColor());
		bar(getX()+8,getY()+8,getX()+32,getY()+32);
		setcolor(0);
			
			break;
		}
		case't':{//trevol
			
			setcolor(getColor());  //primero el cuadrado central
		setfillstyle(SOLID_FILL,getColor());
		bar(getX()+15,getY()+15,getX()+25,getY()+25);
		
		fillellipse(getX()+12,getY()+20,6,6);//ahora los circulos
		fillellipse(getX()+20,getY()+12,6,6);
		fillellipse(getX()+28,getY()+20,6,6);
		fillellipse(getX()+20,getY()+28,6,6);
		setcolor(0);
			
			break;
		}
		case'f':{// para estrella 4 puntas .----four pointed star
			
		setcolor(getColor());
		setfillstyle(SOLID_FILL,getColor());
		fillellipse(getX()+20,getY()+20,15,4);
		fillellipse(getX()+20,getY()+20,4,15);
		setcolor(0);	
			
			break;
		}
		
		case'e':{// para estrella 8 puntas .----eight pointed star
			
			setcolor(getColor());
			
		setfillstyle(SOLID_FILL,getColor());// primero un cuadrado
		bar(getX()+10,getY()+10,getX()+30,getY()+30);
		
		fillellipse(getX()+20,getY()+20,15,4);//ahora encima una estrella 4 puntos
		fillellipse(getX()+20,getY()+20,4,15);

				setcolor(0);	

			
			break;
		}
		
		
	}
	
}



void Ficha::funcion(int caso){//asigna que funcion deberia de hacer la ficha en en dicho instante,
	
	switch(caso){
		
		case 1:{  // solo pintar sea vacio o lleno
			
			pintar();
			
			break;
		}
		
		case 2:{//si tiene un * (esta vacia sin forma) y debe ser un boton visible con funcionalidad
			
			Cuadro_Texto bTn(getX(),getY(),getX()+40-1,getY()+40-1,BROWN,1,(char*)"");
			Cuadro_Texto *btn=&bTn;
			Boton boton(getX(),getY(),getX()+40,getY()+40,false,btn);
			
			if(	boton.precionado()==true){
				
				seleccionada=true;
				}
				
			else{
				seleccionada=false;
		
			}
		
			
			break;
		}
		
		case 3:{// si quiere que se pinte y funcione como boton invisible
			
			pintar();
		
			Boton btn(getX(),getY(),getX()+40,getY()+40,false,NULL);//hace un boton sin cuadro de texto o fondo
			
			if(btn.botonInvisible()==true&&getFigura()!='*'){//prueba su concion de seleccionada
				
	
				if(getSeleccionada()==false){
				seleccionada=true;					
				}
				
				else{
				seleccionada=false;			
				}	
				
			}

			
			break;
		}
		
		case 4:{// si quiere que se pinte como un cuadro blanco----usado para solo poder borrar un mal movimiento o corregir el fondo del tablero
			
				setfillstyle(SOLID_FILL,WHITE);//Blanco  
				bar(getX()+1,getY()+1,getX()+40-1,getY()+40-1);
			
			
			break;
		}
		
	}
	
	
}


string Ficha::toString(){
		stringstream s;
              s<<getX()<<"	"<<getY()<<"	"<<getFigura()<<"	"<<getColor()<<"	"<<seleccionada<<endl;
              return s.str(); 
	}



Ficha::~Ficha()
{
}
