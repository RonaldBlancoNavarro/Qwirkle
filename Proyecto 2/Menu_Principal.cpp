#include "Menu_Principal.h"

Menu_Principal::Menu_Principal()
{
//	primero=NULL;
}


//void Menu_Principal::insertarPrimero ( Partida p) {
// 	primero= new Nodo_Partida (NULL,p,primero); //NULL,lo de p, primero
//}



//void insertarFinal ( Partida * p ) {//problemas con el parametro
//	 actual = primero;
//        //Lista Vacia
//	  if (primero==NULL) {
// 		primero= new Nodo (NULL, p , primero); }// deberia ser.: p->setAnt(NULL), constructor del nodo con gets de p ,p->setsig(primero)  
//	  else {
//		 actual = primero;
//		while (actual->getSigNodo() ! = NULL )  {   // al final
// 			actual=actual->getSigNodo() ;
//		 }
//		 actual->setSigNodo ( new Nodo ( actual, ptrDato, NULL) );
//	}
//}

		
void Menu_Principal::startgame(){
	
	
	//1366 x 768
	initwindow(1366,768,(char*)"Qwirkle");//	1000	700
	setbkcolor(15);//white 15   -----LIGHTGRAY
	cleardevice();
	
	
	Cuadro_Texto titulo(455,80,755,200,LIGHTBLUE,7,(char*)"QWIRKLE");
	
	
	Ficha objeto(100,100,RED,'c',0); 
	Ficha objeto4(100,200,LIGHTRED,'r',0);
	Ficha objeto5(100,300,YELLOW,'s',0);  
	Ficha objeto6(100,400,LIGHTGREEN,'t',0); 
	Ficha objeto7(100,500,BLUE,'f',0);  
	Ficha objeto8(100,600,MAGENTA,'e',0); 
	
	Cuadro_Texto iP(455,230,755,300,BROWN,3,(char*)"	Iniciar Partida");
	Cuadro_Texto *ip=&iP;
	Boton iniciarPartida(455,230,755,300,false,ip);
	
	Cuadro_Texto cP(455,330,755,400,GREEN,3,(char*)"	Cargar Partida");
	Cuadro_Texto *cp=&cP;
	Boton cargarPartida(455,330,755,400,false,cp);	
	
	Cuadro_Texto aD(455,430,755,500,CYAN,3,(char*)"		Acerca de:");
	Cuadro_Texto *ad=&aD;
	Boton acercaDe(455,430,755,500,false,ad);		
	
	Cuadro_Texto S(455,530,755,600,BLACK,3,(char*)"		Salir");
	Cuadro_Texto *s=&S;
	Boton salir(455,530,755,600,false,s);	
	
	Cuadro_Texto eP(785,530,1085,600,DARKGRAY,3,(char*)"		Eliminar Partidas");
	Cuadro_Texto *ep=&eP;
	Boton eliminarPartidas(785,530,1085,600,false,ep);	
	
	Cuadro_Texto rJ(785,430,1085,500,MAGENTA,3,(char*)"		Reglas del Juego");
	Cuadro_Texto *rj=&rJ;
	Boton reglasJuego(785,430,1085,500,false,rj);	
	


	


	while(true){

	titulo.dibujar();
	
	objeto.pintar();
	objeto4.pintar();
	objeto5.pintar();
	objeto6.pintar();
	objeto7.pintar();
	objeto8.pintar();
	
	
	
	if(iniciarPartida.precionado()==true){
		
		setbkcolor(15);//white 15   -----LIGHTGRAY	
		cleardevice();
		
		Cuadro_Texto titulo(455,80,800,200,BLUE,4,(char*)"Inserte sus datos");
		
		
		Cuadro_Texto N(455,230,900,300,GREEN,3,(char*)" Escriba su Nombre:");
		Cuadro_Texto *n=&N;
		Boton escribaNombre(455,230,900,300,false,n);
		
		
		Cuadro_Texto Elija(300,330,655,400,LIGHTBLUE,3,(char*)"Elija el puntaje Final");
		
		
		Cuadro_Texto Vc(700,330,750,400,MAGENTA,3,(char*)"25");
		Cuadro_Texto *vc=&Vc;
		Boton veinticinco(700,330,750,400,false,vc);
		
		Cuadro_Texto C(800,330,850,400,MAGENTA,3,(char*)"50");
		Cuadro_Texto *c=&C;
		Boton cincuenta(800,330,850,400,false,c);
			
		Cuadro_Texto sC(900,330,950,400,MAGENTA,3,(char*)"75");
		Cuadro_Texto *sc=&sC;
		Boton setentayCinco(900,330,950,400,false,sc);
		
		Cuadro_Texto hF(1000,330,1200,400,MAGENTA,3,(char*)"Hasta el fin");
		Cuadro_Texto *hf=&hF;
		Boton Hastafin(1000,330,1200,400,false,hf);
		
		
		Cuadro_Texto cont(455,430,755,500,CYAN,3,(char*)"		Continuar");
		Cuadro_Texto *conti=&cont;
		Boton continuar(455,430,755,500,false,conti);		
		
		Cuadro_Texto S(455,530,755,600,BLACK,3,(char*)"		Salir");
		Cuadro_Texto *s=&S;
		Boton salir(455,530,755,600,false,s);
		
		
		
		titulo.dibujar();
		Elija.dibujar();
		
		
		
		int puntajeF;
		bool ciclo=true;
		//metyerle un while para insertar datoos de jugador
		while(ciclo==true){
			
			//aqui pedirle datos sobre partida y limite puntaje
			
				if(escribaNombre.precionado()){
//					N.escribir();
							escribaNombre.getButton()->escribir();		
				}
			
				if(veinticinco.precionado()){
					puntajeF=25;
				}
				if(cincuenta.precionado()){
					puntajeF=50;
				}
				if(setentayCinco.precionado()){
					puntajeF=75;
				}
				if(Hastafin.precionado()){
					puntajeF=200;
				}
				
				if(continuar.precionado()&&escribaNombre.getButton()->getTexto()!=(char*)" Escriba su Nombre:"&&puntajeF>=25){
					
					//aqui se agrega un nueva partida con su juego de  una vez
					
					

					
//					char* nom=escribaNombre.getButton()->getTexto();
					
//					puntajeF,(char*)nom
					qwirkle.jugar();//empieza juego  mandar nombrey puntaje final por parametro en juego en un caso correcto
					
					ciclo=false;
				}
				
				
				if(salir.precionado()){
					ciclo=false;
					break;
				}

			
			delay(100);
		}
		
		
		if(ciclo==true){
				getch();//lo detiene todo	
		}
		else{//por aquello que se imprimieroan muchas cosas
		setbkcolor(15);//white 15   -----LIGHTGRAY	
		cleardevice();
		}

	}
	
	if(cargarPartida.precionado()==true){
		
//	setbkcolor(15);//white 15   -----LIGHTGRAY
//	cleardevice();	
//		
		cargar();
//		0,(char*)""
//		qwirkle.jugar();
//		
//	setbkcolor(15);//white 15   -----LIGHTGRAY
//	cleardevice();	
	}
	
	
	if(acercaDe.precionado()==true){
		
				
	setbkcolor(15);//white 15   -----LIGHTGRAY
	cleardevice();	
	
	
	
	
		
		while( true){
			
			  
				settextstyle(8,0,2);// 1 pequeño 2 mediano 3 grande
				setcolor(WHITE);//con este se le da el color a las letras
				setbkcolor(RED);
				
				outtextxy(300,100 ,(char*)"Universidad Nacional");
				outtextxy(300,120 ,(char*)"Programacion | ");
				outtextxy(300,140 ,(char*)"Ciclo ||-2019");
				outtextxy(300,160 ,(char*)"Profesor: Máster Gabriel Núñez M.");
				outtextxy(300,180 ,(char*)"Proyecto: Qwirkle");//
				outtextxy(300,200 ,(char*)"Estudiante: Ronald Blanco Navarro");//
				outtextxy(300,220 ,(char*)"Agradecimientos a todos lo que me han apoyado");
				
				setcolor(0);
			
			if(salir.precionado()==true){
				break;
			}
			
			
			delay(100);
		}

		
	setbkcolor(15);//white 15   -----LIGHTGRAY
	cleardevice();
		
	}
	
	
	
	eliminarPartidas.precionado();//metodo destructor de menu principal y borrar todo en el doc de guardado
	
	if(reglasJuego.precionado()==true){
	
					
	setbkcolor(15);//white 15   -----LIGHTGRAY
	cleardevice();	
	
	
		Cuadro_Texto reglas(300,100,600,150,RED, 2,(char*)"Reglas del Juego");
	
		
		while( true){
			
			  
				settextstyle(8,0,2);// 1 pequeño 2 mediano 3 grande
				setcolor(WHITE);//con este se le da el color a las letras
				setbkcolor(RED);
				
				
			
				reglas.dibujar();
				
				outtextxy(200,180 ,(char*)"2 reglas fundamentales convinables o indibiduales en cada fila, de no mas  de 6 piezas : ");				
				outtextxy(300,210 ,(char*)"Mismo color difente forma ");
				outtextxy(300,230 ,(char*)"Misma forma difente color");
				outtextxy(300,250 ,(char*)"Mas reglas y mas en:");
				outtextxy(300,260 ,(char*)"https://misutmeeple.com/2015/10/resena-qwirkle/");

				
				setcolor(0);
			
			if(salir.precionado()==true){
				break;
			}
			
			
			delay(100);
		}

		
	setbkcolor(15);//white 15   -----LIGHTGRAY
	cleardevice();	
	}
	
	
	
	

	
		
	delay(100);
		
		
	if(salir.precionado()==true){
		break;
		
		//para salir del juego
	}	
		
	}

	closegraph();
	
	

}






void Menu_Principal::cargar(){
	
	FILE *archivo;

	
	archivo = fopen("archivo2.txt", "r");
   	fread(&qwirkle ,sizeof( Partida),1, archivo);


	qwirkle.jugar();
	
	   
   fclose(archivo);

	
}

void Menu_Principal::borrarPartida(){
	
	
}

Menu_Principal::~Menu_Principal()
{
}
