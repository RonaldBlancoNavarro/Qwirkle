#include "Jugador.h"

Jugador::Jugador()
{
	nombre=(char*)"";
	puntaje=0;
//	maxPuntaje=0;
	cantFichas=0;
	actual=primero=NULL;
}

void Jugador::setNombre(char* n){
	nombre=n;
}
void Jugador::setPuntage(int p){
	puntaje=p;
}
//void Jugador::setMaxPuntaje(int mp){
//	maxPuntaje=mp;
//}
void Jugador::setCantFichas(int cf){
	cantFichas=cf;
}

char* Jugador::getNombre(){
	return nombre;
}
int Jugador::getPuntaje(){
	return puntaje;
}
//int Jugador::getMaxPuntaje(){
//	return maxPuntaje;
//
//}
int Jugador::getCantFichas(){
	return cantFichas;
}

Nodo_Ficha* Jugador::getPrimero(){
	return primero;
}


void Jugador::insertarPrimero ( Ficha *f) {
 	  actual= primero;
	  if (primero == NULL ) //Lista Vacia
 		primero = new Nodo_Ficha( f, NULL);
      else  {
		 primero = new Nodo_Ficha(f, actual);
      }
      cantFichas++;      
}

void  Jugador ::borrar(Ficha  * f) {  //Busca y elimina un nodo determinado



	if(primero!=NULL){
			
			actual=primero;
			
			if(primero->getPieza()->getFigura()==f->getFigura()&&primero->getPieza()->getColor()==f->getColor()){//si es la primera
				
						primero=primero->getSig();
						delete actual;
						cantFichas--;
			
			}
			else{
     			Nodo_Ficha *anterior;				
			while(actual!=NULL){
				
				if(actual->getPieza()->getFigura()==f->getFigura()&&actual->getPieza()->getColor()==f->getColor()){//sino avanza hasta encontrarla
						anterior->setSig(actual->getSig());
						delete actual;
						cantFichas--;	
					break;
					return;
				}	
				else{
					
							anterior=actual;
							actual=actual->getSig();
				}
			}	
				
			}
			
	}


}


bool Jugador::manipularDeck(bool modo){//recorre el deck del modo seleccionado y retorna si encontro una o varias seleccionadas
	
	bool elegida=false;	
		
		int xpl=400;
	actual=primero;
	while(actual!=NULL){
	
		actual->getPieza()->setX(xpl);
		actual->getPieza()->setY(635);
		actual->getPieza()->funcion(3);//todo esta es para pintar()
		
		
		
		if(elegida==false&&actual->getPieza()->getSeleccionada()==true){
			elegida=true;
		}
		
		if(modo==0&&elegida==true){
				
			 if(actual->getSig()!=NULL){
			actual->getSig()->getPieza()->setSeleccionada(false);	
			}
			
		}
		
		
		actual=actual->getSig();
		xpl=xpl+70;
		

	}
	
	if(elegida==true){
		return true;
	}
	else{
		return false;
	}
		
}


string Jugador::toString() {
	int contador=0;
	stringstream s;
 	actual= primero;
	s << "Contenido de la lista:"<<endl;
     while (actual!=NULL){    //primero no se mueve
     			contador++;
     			s<<contador<<endl;
               s << actual->toString()<<endl;
		  actual= actual->getSig();
      }
	return s.str();
} 


Ficha Jugador::retornarSeleccionada(){//retorna una ficha si fue selecionada
	
	Ficha *aux;
	actual= primero;
     while (actual!=NULL){    //primero no se mueve
     		
     		if(actual->getPieza()->getSeleccionada()==true){//si se selecciono se detiene
     			break;	
			 }
			 else{
			 	
			  actual= actual->getSig();		 	//sino continua
			 	
			 }
      }
      
    aux=actual->getPieza();
	
	borrar(actual->getPieza());// borra la ficha-----el numero de fichas en bolsa se reduce pero de  esto lleva la cuneta en borrar	
	
	Ficha elegida(0,0,aux->getColor(),aux->getFigura(),false);//taspaso a ficha normal
	
	return elegida;
      
 }


Jugador::~Jugador()
{
}
