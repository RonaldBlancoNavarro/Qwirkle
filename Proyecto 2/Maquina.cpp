#include "Maquina.h"

Maquina::Maquina()
{ puntaje=0;
cantFichas=0;
	primero=actual=NULL;

}
//sets
void Maquina::setPuntage(int p){
	puntaje=p;
}

void Maquina::setCantFichas(int cf){
	cantFichas=cf;
}
//gets
int Maquina::getPuntaje(){
	return puntaje;
}

int Maquina::getCantFichas(){
	return cantFichas;
}

Nodo_Ficha* Maquina::getPrimero(){
	return primero;
}



void Maquina::insertarPrimero ( Ficha *f) {
 	  actual= primero;
	  if (primero == NULL ) //Lista Vacia
 		primero = new Nodo_Ficha(f, NULL);
      else  {
		 primero = new Nodo_Ficha (f, actual);
      }
      cantFichas++;      
}



void  Maquina ::borrar(Ficha  * f) {  //Busca y elimina un nodo determinado


	if(primero!=NULL){
			
			actual=primero;
			
			if(primero->getPieza()->getFigura()==f->getFigura()&&primero->getPieza()->getColor()==f->getColor()){
				
						primero=primero->getSig();
						delete actual;
						cantFichas--;
			
			}
			else{
     			Nodo_Ficha *anterior;				
			while(actual!=NULL){
				
				if(actual->getPieza()->getFigura()==f->getFigura()&&actual->getPieza()->getColor()==f->getColor()){
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


string Maquina::toString() {
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



Ficha Maquina::retornarSeleccionada(){//retorna una ficha si fue selecionada
	
	Ficha *aux;
	actual= primero;
     while (actual!=NULL){    //primero no se mueve
     		
     		if(actual->getPieza()->getSeleccionada()==true){
     			break;	
			 }
			 else{
			 	
			  actual= actual->getSig();		 	
			 	
			 }
      }
      
    aux=actual->getPieza();
	
	borrar(actual->getPieza());//el numero de fichas en bolsa se reduce pero se lleva la cuneta en borrar	
	
	Ficha elegida(0,0,aux->getColor(),aux->getFigura(),false);
	
	return elegida;
      
 }


Maquina::~Maquina()
{
}
