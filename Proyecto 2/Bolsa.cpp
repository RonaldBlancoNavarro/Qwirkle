#include "Bolsa.h"

Bolsa::Bolsa()
{
	primero=actual=NULL;
	cantFichas=0;
}

Bolsa::Bolsa(Nodo_Ficha *p,Nodo_Ficha *a,int cf){
	primero=p;
	actual=a;
	cantFichas=cf;
}


//sets
void Bolsa::setCantFichas(int cf){
	cantFichas=cf;
}

Nodo_Ficha* Bolsa::getPrimero(){
	return primero;
}

void Bolsa::insertarPrimero ( Ficha *f) {//inserta en la primer poscion de la bolsa
 	  actual= primero;
	  if (primero == NULL ) //Lista Vacia
 		primero = new Nodo_Ficha( f, NULL);
      else  {
		 primero = new Nodo_Ficha (f, actual);
      }
setCantFichas(getCantFichas()+1);
}


void  Bolsa::borrar(Ficha   *f) {  //Busca y elimina un nodo determinado


	if(primero!=NULL){
			
			actual=primero;
			
			if(primero->getPieza()->getFigura()==f->getFigura()&&primero->getPieza()->getColor()==f->getColor()){//elimina el nodo si es el primero
				
						primero=primero->getSig();
						delete actual;
						cantFichas--;
			
			}
			else{
     			Nodo_Ficha *anterior;				
			while(actual!=NULL){// recorre la lista hasta que encuntra el nodo
				
				if(actual->getPieza()->getFigura()==f->getFigura()&&actual->getPieza()->getColor()==f->getColor()){
						
						anterior->setSig(actual->getSig()); //al nodo anterio de actual le asigna como siguiente el siguinte nodo de actual
						delete actual;
						cantFichas--;	
					break;
					return;
				}	
				else{
					
							anterior=actual; //continua recorrinedo la lista
							actual=actual->getSig();
				}
			}	
				
			}
			
	}


}




Ficha Bolsa::seleccionarAleatoria(){
	
	//meterle el contador del enrredo de las fichas
	
	srand(time(NULL));
	
	int num;
	num=1+rand()%(getCantFichas());// por ser  108 piezas
	

	if(num==1){
	actual=primero;
	}
	else{

	int i=1;	
		
	actual=primero;
	
	while(i<num&&actual->getSig()!=NULL){//actual!=NULL// pero parece estar bien
		
		
		
		actual=actual->getSig();
		i++;
	}
		
	}
	
	Ficha *aux=actual->getPieza();
	
	borrar(actual->getPieza());//el numero de fichas en bolsa se reduce pero se lleva la cuneta en borrar	
	
	Ficha elegida=*aux;
	
	return elegida;
}

void Bolsa::rellenarLista(){// rellena lista desde cero o la reinicia

//Ficha base;
int colr=0;
char fig='*';

	if(primero==NULL){
		
	
		
		for(int i=0;i<3;i++){// 36 x 3 =108
		for(int j=0;j<6;j++){//for  de figura
		
		
		switch(j){
			case 0:{
				fig='c';//circulo
				break;
			}
			
			case 1:{
				fig='r';//rombo
				break;
			}
			
			case 2:{
				fig='s';//cuadrado
				break;
			}
			
			case 3:{
				fig='t';//trevol
				break;
			}
			
			case 4:{
				fig='f';//estrella 4 puntas
				break;
			}
			case 5:{
				fig='e';//estrella de 8 puntas
				break;
			}
		}
		
		
			for(int k=0;k<6;k++){// for de color
				
			switch(k){
				
			case 0:{
				colr=RED;
				break;
			}
			
			case 1:{
				colr=LIGHTRED;
				break;
			}
			
			case 2:{
				colr=YELLOW;
				break;
			}
			
			case 3:{
				colr=LIGHTGREEN;
				break;
			}
			
			case 4:{
				colr=BLUE;
				break;
			}
			case 5:{
				colr=MAGENTA;
				break;
			}
		}
//			base.setX(0);
//			base.setY(0);
//			base.setFigura(fig);
//			base.setColor(colr);
//			base.setSeleccionada(0);

////			Ficha base(0,0,colr,fig,false);
//			insertarPrimero(&base);

			Ficha *base=new Ficha(0,0,colr,fig,false);
			insertarPrimero(base);
			
			}
			
			
		}
		
		
	}	
		
		
		
	}


}


void Bolsa::contador(){
//lleva la contabilidad de las fichas cuando se guarda o algo asi


//aqui iria talvez lo de recuperrar los datos del documento



int cr=3;//circulo rojo   4
int co=3;//c naranja		---LIGHTRED  12
int cy=3;// amarillo		14
int cg=3;// verde			2
int cb=3; //azul		1
int cm=3; //morado  			MAGENTA  5

int rr=3,ro=3,ry=3,rg=3,rb=3,rm=3;//ahora los rombos

int sr=3,so=3,sy=3,sg=3,sb=3,sm=3;// cuadrados

int tr=3,to=3,ty=3,tg=3,tb=3,tm=3;//<trevolees

int fr=3,fo=3,fy=3,fg=3,fb=3,fm=3;//estrella 4 puntas

int er=3,eo=3,ey=3,eg=3,eb=3,em=3;//estrella 8 puntas

///de de cada una cuando se cargue el tablero se restan lasa  que ya estan a la bolsa









}

int Bolsa::getCantFichas(){
	return cantFichas;
}


string Bolsa::toString() {
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



Bolsa::~Bolsa()
{	 while (primero != NULL ) {
		actual = primero;
		primero= primero->getSig();
		 delete  actual;
	}

}
