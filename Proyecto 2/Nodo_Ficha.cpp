#include "Nodo_Ficha.h"

Nodo_Ficha::Nodo_Ficha()
{pieza=NULL;
sig=NULL;
}

Nodo_Ficha::Nodo_Ficha(Ficha *p,Nodo_Ficha *s)
{
	pieza=p;
	sig=s;
}
//sets
void Nodo_Ficha::setPieza(Ficha *p ){
	pieza=p;
}

void Nodo_Ficha::setSig(Nodo_Ficha *s){
	sig=s;
}


//gets
Ficha* Nodo_Ficha::getPieza(){
	return *&pieza;
}

Nodo_Ficha* Nodo_Ficha::getSig(){
	return sig;
}



string  Nodo_Ficha::toString() {  
		stringstream s;
              s<< getPieza()->toString()<<endl;
              return s.str();   
      }  

Nodo_Ficha::~Nodo_Ficha()
{
}
