#include "Partida.h"

Partida::Partida()
{
	puntajeLimite=25;
	
	
}

Partida::Partida(Bolsa b,Jugador j,Maquina m,int pl){
	bag=b;
	player=j;
	machine=m;
	puntajeLimite=pl;

	
}


//sets
void Partida::setBag(Bolsa b){
	bag=b;
}

void Partida::setPlayer(Jugador j){
	player=j;
}

void Partida::setMachine(Maquina m){
	machine=m;
}

void Partida::setTablero(Ficha t[][20]){
	
for(int i=0;i<13;i++){
	for(int j=0;j<20;j++){
		tablero[i][j]=t[i][j];
	}
}
	
}

void Partida::setPuntajeLimite(int pl){
	puntajeLimite=pl;
}



//gets
Bolsa Partida::getBag(){
	return bag;
}
Jugador Partida::getPlayer(){
	return player;
}
Maquina Partida::getMachine(){
	return machine;
}


int Partida::getPuntajeLimite(){
	return puntajeLimite;
}





bool Partida::guardar(){//guarda la partida
	

	Partida save;//crea un objeto tipo partida
	save.setBag(bag);
	save.setMachine(machine);
	save.setPlayer(player);
	save.setTablero(tablero);
	save.setPuntajeLimite(puntajeLimite);
	
	
   FILE *archivo;


   archivo = fopen("Partidas.txt", "w");
   fwrite(&save ,sizeof( Partida),1, archivo);//tecnicamente escribe los datos en el documento
   fclose(archivo);


return true;

}

void Partida::rellenarBarajaJugador(){//rellena la baraja del jugador trayendo las fichas densde la bolsa
	
		Ficha aux;
		
		while(player.getCantFichas()<6){ 
		
//			insertar jugador fichas y aumentar cant

			aux=bag.seleccionarAleatoria();//saca una ficha aleatorea de la bolsa
			Ficha *base=new Ficha(0,0,aux.getColor(),aux.getFigura(),false);

		
			player.insertarPrimero(base);//inserta en la lista del jugador
		}	
	
}


void Partida::rellenarBarajaMaquina(){//rellena la baraja de la maquina trayendo las fichas densde la bolsa
		Ficha aux;
	
			while(machine.getCantFichas()<6){//for(int j=0;j<6;j++){
//			insertar maquina fichas y aumentar cant
			
			aux=bag.seleccionarAleatoria();//saca una ficha aleatorea de la bolsa
			Ficha *base=new Ficha(0,0,aux.getColor(),aux.getFigura(),false);

		
			machine.insertarPrimero(base);//inserta en la lista del pc
			
		}
}


char Partida::seleccionarTurno(char turno){//selecciona cual turno inicia partida
	

	if(turno=='j'){//para el jugador
	return 'm';	

	}
	else if(turno=='m'){//para la maquina
			
	return 'j';
		
	}else if(turno=='?'){	//para turno =='?'
		
	/*lo correcto seria recorream la lista de piezas de jugador y maquina 
	llevando un control de todas las caracteristicas talves con un switch de color y forma
	despues elijir la caracteristica mas encontrada dentro de cada lista y evaluar cual es mas grande.
	Dificir por cuestiones de tiempo*/
	
	
	return 'j';
	

		
	}	
	
}


//int pl ,char *nom
void Partida::jugar( ){//tecnimente es el juego en si
	
	
			player.setNombre((char*)"Raul"); //asigna nombre a jugador y puntaje al que termina el juego
			setPuntajeLimite(25);
	
	
	
//		if(player.getPuntaje()==0&&machine.getPuntaje()==0){//comprobar si ya se empezola partida y necesita cargar
				
		
			bag.rellenarLista();
//			cout<<bag.toString();			
			
			rellenarBarajaJugador();
			rellenarBarajaMaquina();
//		}
		
//esto es para revisar el correcto insertado de fichas




		setbkcolor(15);//white 15 
		cleardevice();
		
		
		
		
//creacion de botones y cuadros de texto

	Cuadro_Texto titulo(950,20,1350,80,LIGHTBLUE,4,(char*)"QWIRKLE");

	Cuadro_Texto fichasMaquina(20,20,900,70,BROWN,2,(char*)"Fichas del computador: ");
	
	Cuadro_Texto fichasJugador(20,630,900,680,BROWN,2,(char*)"Fichas de: ");//cambiar a nombre del jugador
	
	Cuadro_Texto finjuego(950,100,1350,150,RED,1,(char*)"Puntaje limite del juego: ");//ver como se pone eso	
	
	Cuadro_Texto cantPiezasBolsa(950,175,1350,225,RED,1,(char*)"Cantidad de piezas en bolsa: ");//ver como se pone eso
	
	
	Cuadro_Texto Rep(950,250,1350,300,BLUE,1,(char*)"Reponer Piezas Jugadas");
	Cuadro_Texto *rep=&Rep;
	Boton reponer(950,250,1350,300,false,rep);

	Cuadro_Texto inter(950,325,1350,375,BLUE,1,(char*)"Intercambiar Piezas");
	Cuadro_Texto *interc=&inter;
	Boton intercambiar(950,325,1350,375,false,interc);

	Cuadro_Texto interall(950,400,1350,450,BLUE,1,(char*)"Intercambiar todas las Piezas");
	Cuadro_Texto *intercall=&interall;
	Boton intercambiartodo(950,400,1350,450,false,intercall);
	
	Cuadro_Texto save(950,475,1350,525,BLACK,1,(char*)"Guardar Partida");
	Cuadro_Texto *guardar=&save;
	Boton guardarPartida(950,475,1350,525,false,guardar);
		
	Cuadro_Texto exit(950,550,1350,600,BLACK,1,(char*)"Salir de la Partida");
	Cuadro_Texto *salir=&exit;
	Boton salirPartida(950,550,1350,600,false,salir);
	
	
	Cuadro_Texto terminar(950,625,1350,675,GREEN,1,(char*)"Terminar Turno");
	Cuadro_Texto *finish=&terminar;
	Boton terminarTurno(950,625,1350,675,false,finish);




	
	//creacion de variables necesarias para la partida
	
	
		bool modo=0;//segun cuantas piezas del deck pude seleccionar en dicho momento
		//modo 0 solo se puede selecionar una ficha
		//modo 1 se selecciona ahora varias para poder en dicho caso  y no puedo tacar nada en el tablero	
		
		
		bool end=false;
		
		bool cambioTurno=false;
		
		char turno='?';
		//? seria dado para saber quien inicia la partida
		//j para jugador
		//m para maquina
		
		//se selecciona quien iniciara la partida antes de esta iniciarse ya sea que se este iniciando o cargando
//		if(turno=='?'){
			
//			if(seleccionarTurno(turno)=='j'){
				turno='j';
				modo=0;
//				
//			}else{
//				
//				if(seleccionarTurno(turno)=='m'){
//					turno='m';
//					modo=1;
//					
//				}
//			}
//			
//		}		
		
		
		int posI; //estas variables se usaran como 
		int posJ;  
		
	
		
	while(end==false&&player.getPuntaje()<=getPuntajeLimite()&&machine.getPuntaje()<=getPuntajeLimite()){  //en este while pasaran loseventos del juego


		titulo.dibujar();

		fichasMaquina.dibujar();
		
		int_To_charpuntero(850,25,machine.getPuntaje());//muestra puntaje de la maquina
		
		
		int xpc=400;  // solamente pinta de manera discreta las fichas de la maquina 
		for (int i=0;i<machine.getCantFichas();i++){
			
			setfillstyle(SOLID_FILL,BLACK);//son cuadrados negros simulando fichas  
			bar(xpc,25,xpc+40-1,25+40-1);	
			
			xpc=xpc+70;
		}


	
		fichasJugador.dibujar();
		
		if(player.getNombre()!=""){			//aqui se grafica el nombre del jugador
			settextstyle(8,0,3);// 1 pequeño 2 mediano 3 grande
			setcolor(WHITE);
			setbkcolor(BROWN);
		outtextxy(170,645,player.getNombre());
		}

		int_To_charpuntero(850,635,player.getPuntaje());//graficado del puntage del jugador
		
		
		
		// graficado y manipulacion de las fichas del jugador	
		if(player.getPrimero()!=NULL){
		player.manipularDeck(modo);	//modo 0 una ficha seleccionable---modo 1 varias a la vez
		
		}





		//para la matris----dibujado solo de los cuadro de la matriz 
		int x=50;//punto inicial para asignar posiciones x--y
		int y=50;
		for(int i=0;i<13;i++){//13				recorrido de la matriz que seria el tablero
		y=y+40;
		
			for(int j=0;j<20;j++){  //  13x20---------------estas son las dimenciones del tablero
				x=x+40;
				
				//meramente ilustrativo estas separaciones
				setcolor(GREEN);
				rectangle(x,y,x+40,y+40);
				setcolor(0);
			
				//asinacion de posicion para graficado del tablero
				tablero[i][j].setX(x);
				tablero[i][j].setY(y);
				
				
				
		//calculo de como se debe comportar el tablero en definido momento durante el turno del jugador
				if(tablero[i][j].getFigura()=='*'&&modo==0){
					
					if(player.getPuntaje()==0&&i==6&&j==10){//al puro inicio de la partida
							
							tablero[6][10].funcion(2);
							
							if(tablero[6][10].getSeleccionada()==true){
									posI=i;
									posJ=j;
								}
					}
					else{
						
						if(autorizar(i,j,'j')){// pregunta a un metodo si es correcto que la ficha se pueda meter  o no dentro de ese espacio 
						//
							
						tablero[i][j].funcion(2);
						
						if(tablero[i][j].getSeleccionada()==true){//pregunta si fue seleccionada para ser rellenada por una ficha del deck
								posI=i;
								posJ=j;
							}
							
						}
						else{
						tablero[i][j].funcion(4);//basicamente dice pinte un cuadrado blanco
							
						}
							
					}
						
				}
				
				
				else{//calculo de como se debe comportar el tablero duante el turno del computador			
					
					if(tablero[i][j].getFigura()!='*'||modo==1){//pinte cuadrados negros vacios donde no se puede insertar fichas
					
							tablero[i][j].funcion(1);

						
					}
					if(tablero[i][j].getFigura()=='*'&&turno=='m'){//en el turno del pc
							
								
							Nodo_Ficha *aux=machine.getPrimero();
							
							while (aux!=NULL){    //revisa todas las fichas del computador posicion por posicion que puedan colocarse en el tablero
								
									aux->getPieza()->setSeleccionada(true);//primero no se muev
								
									if(autorizar(i,j,'m')==true){//si se autorisa su colocacion cambian de estar en la lista de la maquina al tablero
										
										//aqui se sacaria de la lista de maquina y se insertarian en esa posicion de la mesa
											Ficha aux2=machine.retornarSeleccionada();
											tablero[i][j]=aux2;
											machine.setPuntage(machine.getPuntaje()+1);
										
										
									}else{
									
									aux->getPieza()->setSeleccionada(false);
									
									aux= aux->getSig();	//prueba con otra mas de la lista del pc
									}
									
									
									
								
							}	
							
							
						}
						
									
				}
	
	
	
			if(x==850){
				x=50;//resetea x para no salirse de la pantalla
			}
				
			}
			
		}
	
	
	// ya que se reviso la mesa, se recarga fichas o cambia totalmente 
	if(turno=='m'){
	
//		
//		// contador de puntos
//		
//		
		if(machine.getCantFichas()<=6){// si esta incompleto rellenar 
			rellenarBarajaMaquina();
			
		}else{//si esta completo cambiar con fichas de la bolsa
			
			
			while(machine.getCantFichas()>0){//vacia la lista del computador
				
			
			//darle a primero que esta selecionado
			
			machine.getPrimero()->getPieza()->setSeleccionada(true);
			
			//segundo sacarlo de la lista para insertarlo en bolsa
			Ficha tranportador=machine.retornarSeleccionada();
			
			//ahora lo inserta de nuevo en la bolsa
			Ficha *base=new Ficha(0,0,tranportador.getColor(),tranportador.getFigura(),false);
			bag.insertarPrimero(base);
			}
			
			//cuando ya termino de sacar fichas le inserta de nuevo a machine
			rellenarBarajaMaquina();
			
		}
		
		turno='j';  //al terminar las acciones del pc se cambia de turno
		modo=0;
	}
	
	
	
		finjuego.dibujar();// mostraria el puntaje al que termina la partida
		int_To_charpuntero(1300,105,getPuntajeLimite());
		
		
		cantPiezasBolsa.dibujar();//mostraria la cantidad de piezas de la bolsa que faltan por usar
		int_To_charpuntero(1300,180,bag.getCantFichas());
		
		
		
		if(reponer.precionado()==true){//seria para reponer fichas en el turno del jugado, si la cantidad de fichas es menor a 6
			
			
		}
		
		if(	intercambiar.precionado()==true){//seria dada solo en el turno del jugador y que tengag las 6 fichas y puede elegir varias a cambiar,pero vale un turno
//			modo=1;
//			cambioTurno=true;
//			
//			for(int i=0;i<player.getCantFichas();i++){
//			
//			//encontrar la que se encuentra seleccionada
//			// sacarlo de la lista para insertarlo en bolsa
//			Ficha tranportador=player.retornarSeleccionada();
//			
//			//ahora lo inserta de nuevo en la bolsa
//			Ficha *base=new Ficha(0,0,tranportador.getColor(),tranportador.getFigura(),false);
//			bag.insertarPrimero(base);
//			}
//			
//			//cuando ya termino de sacar fichas le inserta de nuevo a machine
//			rellenarBarajaJugador();
		}
		
		if(intercambiartodo.precionado()==true){//seria dada solo en el turno del jugador y que tengag las 6 fichas y cambia todas las fichas, pero vale un turno
			modo=1;
			cambioTurno=true;
			
			while(player.getCantFichas()>0){
				
			
			//darle a primero que esta selecionado
			
			player.getPrimero()->getPieza()->setSeleccionada(true);
			
			//segundo sacarlo de la lista para insertarlo en bolsa
			Ficha tranportador=player.retornarSeleccionada();
			
			//ahora lo inserta de nuevo en la bolsa
			Ficha *base=new Ficha(0,0,tranportador.getColor(),tranportador.getFigura(),false);
			bag.insertarPrimero(base);
			}
			
			//cuando ya termino de sacar fichas le inserta de nuevo a machine
			rellenarBarajaJugador();			
//			

		}
		
		if(terminarTurno.precionado()==true&&cambioTurno==true){//se daria cuando la cantidad de fichas del jugador sean 0o mas o se intercambiasen fichas con la bolsa
			
//			metodo que contara los puntos	
			rellenarBarajaJugador();//metodo para volver a llenar la lisyta del jugador


			if(turno=='j'){ //al terminar el turno del jugador se apreta aqui y se cabia a turno de pc
				turno='m';
				modo=1;
				
			}

			cambioTurno=false;
		}
		
		
		
		if(guardarPartida.precionado()==true){// guarda el avance de la partida
			modo=1;
//			guardar();  //como guardar no funciono entonces se hace eso aqui

			Partida save;
			save.setBag(bag);
			save.setMachine(machine);
			save.setPlayer(player);
			save.setTablero(tablero);
			save.setPuntajeLimite(puntajeLimite);
			
			
		   FILE *archivo;
		
		
		   archivo = fopen("Partidas.txt", "w");
		   fwrite(&save ,sizeof( Partida),1, archivo);//tecnicamente lo guarda
		   fclose(archivo);
		}
		
		if(salirPartida.precionado()==true){//sale de la partida si no se apreto guardar partida no guarda
		 	end=true;	
		}	
		
	
		if(tablero[posI][posJ].getSeleccionada()==true&&player.manipularDeck(modo)==true&&modo==0&&player.getPrimero()!=NULL){//revisa si se puede trasladar una ficha selecioada del deck del jugador al tablero y lo hace
			cambioTurno=true;
			player.setPuntage(player.getPuntaje()+1);
			trasladar(posI,posJ);//se usa para trasladar fichas del jugador a la mesa
		}
	
	
	
			delay(100);
	}
		
		//para cuando termino la partida			
			
			
				if(player.getPuntaje()>machine.getPuntaje()){//si el vencedor es el jugador
						
						setbkcolor(15);//white 15   -----LIGHTGRAY
						cleardevice();
					
		Cuadro_Texto felicitaciones(300,300,500,400,BLUE, 2,(char*)"Ganaste el Juego");
					
					while(true){
						
						felicitaciones.dibujar();
						
						if(salirPartida.precionado()==true){
							break;
						}
						delay(100);
					}
					
						setbkcolor(15);//white 15   -----LIGHTGRAY
						cleardevice();
				}
				
				
				else if(machine.getPuntaje()>player.getPuntaje()){//si el vencedor es el pc
					
						setbkcolor(15);//white 15   -----LIGHTGRAY
						cleardevice();
					
					
					while(true){
						
					settextstyle(8,0,2);// 1 pequeño 2 mediano 3 grande
					setcolor(WHITE);//con este se le da el color a las letras
					setbkcolor(RED);
						
					outtextxy(300,240 ,(char*)"Gano la maquina");
					
						
						if(salirPartida.precionado()==true){
							break;
						}		
						delay(100);				
					}
					
						setbkcolor(15);//white 15   -----LIGHTGRAY
						cleardevice();
					
					
				}
		
				
setbkcolor(15);//white 15  
cleardevice();
}









void Partida::trasladar(int i, int j){//traslada ficha de player a tablero

//primero encuentra ficha seleccionada en el deck
	Ficha aux=player.retornarSeleccionada();


//luego revisa si se seleciono a alguna de las posiciones del tablero
	if(tablero[i][j].getSeleccionada()==true){
		
//por ultimo hace el traspaso		
		tablero[i][j]=aux;
		
	}

}





bool Partida::autorizar(int posI,int posJ, char turno){//metodo que autoriza la poscbilidad de colocar una ficcha en un respestiva poscicion
	
	Nodo_Ficha *aux;
	
	if(turno=='j'){//para el jugador
		
		aux=player.getPrimero();
		
		while (aux!=NULL){    //primero no se mueve hasta que detecta la ficha seleccionada
			
			if(aux->getPieza()->getSeleccionada()==true){
				break;//cuando la encuentra se detiene
			}
			else{
				aux= aux->getSig();
			}
			
		}
		
		if(aux==NULL){
			return false;
		}
		
		
	}
	
	else if(turno=='m'){//para la maquina
		
		aux=machine.getPrimero();
		
		while (aux!=NULL){    //primero no se mueve
			
			if(aux->getPieza()->getSeleccionada()==true){
				break;//cuando la encuentra se detiene
			}
			else{
				aux= aux->getSig();
			}
			
		}
		
		if(aux==NULL){
			return false;
		}
		
		
	}
	
	
	char fig=aux->getPieza()->getFigura();// se hace una trasnformacion para tener que escribir menos
	int col=aux->getPieza()->getColor();
	
	
	
	//se crean muchas variables para poder calcular correctamente la validaciones
	bool derecha=false;
	bool izquierda=false;
	bool arriba=false;
	bool abajo=false;
	
	
	
	bool derechacolor=false;//grado de aceptacion de la derecha
	bool izquierdacolor=false;//grado de aceptacion de la izqierda
	bool arribacolor=false;//grado de aceptacion de arriva
	bool abajocolor=false;//grado de aceptacion de abajo	
	
	
	bool arribafigura=false;//grado de aceptacion de arriva
	bool abajofigura=false;//grado de aceptacion de abajo
	bool derechafigura=false;//grado de aceptacion de la derecha
	bool izquierdafigura=false;//grado de aceptacion de la izqierda	

	
	//basicamente pregunta que si alguno de los espacios en el tablero que estan a su alrededor estan llenos   
if((tablero[posI][posJ].getFigura()!='*')||(tablero[posI+1][posJ].getFigura()!='*')||(tablero[posI-1][posJ].getFigura()!='*')||(tablero[posI][posJ+1].getFigura()!='*')||(tablero[posI][posJ-1].getFigura()!='*')){
	
//empiezan las validaciones mas generales	
	
if((tablero[posI][posJ+1].getFigura()!='*')){ //derecha
	
	for(int j=posJ+1;j<posJ+6;j++){
			
			if(tablero[posI][j].getFigura()=='*'||j==0||j==19){//si esta vacio
				derecha=true;
				break;
			}
			else{
				
				if(j==posJ+6){
					
					if(tablero[posI][j].getFigura()=='*'){//para delimitar el fin de la fila
						derecha=true;
						break;
					}else{
						derecha=false;
						break;						
					}
					
				}else{
					
					if((tablero[posI][j].getColor()==col&&tablero[posI][j].getFigura()!=fig)^(tablero[posI][j].getFigura()==fig&&tablero[posI][j].getColor()!=col)){//si tiene la figura que se va a insertar algo que consida con esto
						derecha=true;//reviso que si se puede por color o figura
					}
					else{
						
						derecha=false;
						break;
					}					
					
				}
				
				
					
			}
			
			
		}


	
}

	
	

if((tablero[posI][posJ-1].getFigura()!='*')){//izquierda
	
	
		for(int j=posJ-1;j>posJ-6;j--){
			
			if(tablero[posI][j].getFigura()=='*'||j==0||j==19){//si esta vacio
				izquierda=true;
				break;
			}
			else{
				
				if(j==posJ-6){
					
					if(tablero[posI][j].getFigura()=='*'){//para delimitar el fin de la fila
						izquierda=true;
						break;
					}else{
						izquierda=false;
						break;						
					}
					
				}else{
					
					if((tablero[posI][j].getColor()==col&&tablero[posI][j].getFigura()!=fig)^(tablero[posI][j].getFigura()==fig&&tablero[posI][j].getColor()!=col)){//si tiene la figura que se va a insertar algo que consida con esto
						

						
						izquierda=true;//reviso que si se puede por color o figura
					}
					else{
						
						izquierda=false;
						break;
					}					
					
				}
				
				
					
			}
			
			
		}		
	
	
	
}




if((tablero[posI-1][posJ].getFigura()!='*')){//arriba


		for(int i=posI-1;i>posI-6;i--){// arriva 
			
			if(tablero[i][posJ].getFigura()=='*'||i==0||i==12){//si esta vacio
				arriba=true;
				break;
			}
			else{
				
				if(i==posI-6){
					
					if(tablero[i][posJ].getFigura()=='*'){//para delimitar el fin de la fila
						arriba=true;
					}else{
						arriba=false;
						break;						
					}
					
				}else{
					
					if((tablero[i][posJ].getColor()==col&&tablero[i][posJ].getFigura()!=fig)^(tablero[i][posJ].getFigura()==fig&&tablero[i][posJ].getColor()!=col)){//si tiene mismo color pero diferente figura a la que se va a insertar
						arriba=true;
					}
					else{
						
						arriba=false;
						break;
					}					
					
				}
				
				
					
			}
			
			
		}		


}



if((tablero[posI+1][posJ].getFigura()!='*')){//abajo

		for(int i=posI+1;i<posI+6;i++){// abajo 
			
			if(tablero[i][posJ].getFigura()=='*'||i==0||i==12){//si esta vacio
				abajo=true;
				break;
			}
			else{
				
				if(i==posI+6){
					
					if(tablero[i][posJ].getFigura()=='*'){//para delimitar el fin de la fila
						abajo=true;
					}else{
						abajo=false;
						break;						
					}
					
				}else{
					
					if((tablero[i][posJ].getColor()==col&&tablero[i][posJ].getFigura()!=fig)^(tablero[i][posJ].getFigura()==fig&&tablero[i][posJ].getColor()!=col)){//si tiene mismo color pero diferente figura a la que se va a insertar
						
				
						abajo=true;
					}
					else{
						
						abajo=false;
						break;
					}					
					
				}
				
				
					
			}
			
			
		}


}

	
		
}
else{
	return false;//si no tiene ninguno lleno al lado no se puede hacer nada
}




//ahora el verdicto final con validaciones mas especificas



///		abajo		arriba			derecha			izq			
if((tablero[posI+1][posJ].getFigura()!='*')&&(tablero[posI-1][posJ].getFigura()!='*')&&(tablero[posI][posJ+1].getFigura()!='*')&&(tablero[posI][posJ-1].getFigura()!='*')&&derecha==true&&izquierda==true&&arriba==true&&abajo==true){//todos

return true;
}

///				arriba			derecha			izq			
if((tablero[posI-1][posJ].getFigura()!='*')&&(tablero[posI][posJ+1].getFigura()!='*')&&(tablero[posI][posJ-1].getFigura()!='*')&&derecha==true&&izquierda==true&&arriba==true){//der arriba izq

return true;
}

///		abajo					derecha			izq			
if((tablero[posI+1][posJ].getFigura()!='*')&&(tablero[posI][posJ+1].getFigura()!='*')&&(tablero[posI][posJ-1].getFigura()!='*')&&derecha==true&&izquierda==true&&abajo==true){

return true;
}

///		abajo		arriba						izq			
if((tablero[posI+1][posJ].getFigura()!='*')&&(tablero[posI-1][posJ].getFigura()!='*')&&(tablero[posI][posJ-1].getFigura()!='*')&&izquierda==true&&arriba==true&&abajo==true){//todos

return true;
}


///		abajo		arriba			derecha						
if((tablero[posI+1][posJ].getFigura()!='*')&&(tablero[posI-1][posJ].getFigura()!='*')&&(tablero[posI][posJ+1].getFigura()!='*')&&derecha==true&&arriba==true&&abajo==true){//todos

return true;
}







///				arriba			derecha						
if((tablero[posI-1][posJ].getFigura()!='*')&&(tablero[posI][posJ+1].getFigura()!='*')&&derecha==true&&arriba==true){//

//derecha

			if((tablero[posI][posJ+1].getColor()==col&&tablero[posI][posJ+1].getFigura()!=fig)){
				derechacolor=true;
			}else{
				derechacolor=false;
			}
			
			if((tablero[posI][posJ+1].getFigura()==fig&&tablero[posI][posJ+1].getColor()!=col)){
				derechafigura=true;
			}else{
				derechafigura=false;
			}
						

//arriba

			if((tablero[posI-1][posJ].getColor()==col&&tablero[posI-1][posJ].getFigura()!=fig)){
				arribacolor=true;
			}else{
				arribacolor=false;
			}
			
			
			if((tablero[posI-1][posJ].getFigura()==fig&&tablero[posI-1][posJ].getColor()!=col)){
				arribafigura=true;
			}else{
				arribafigura=false;
			}
//		

//decision


	if((derechacolor==true&&arribacolor==true)==true){
		return true;
	}else{
		if((derechacolor==true&&arribafigura==true)==true){
					return true;

		}else{
			if((derechafigura==true&&arribacolor==true)==true){
						return true;

			}else{
				if((derechafigura==true&&arribafigura==true)==true){
							return true;

				}else{
					return false;
				}
			}
		}
	}


//return true;
return false;


}

///				arriba						izq			
if((tablero[posI-1][posJ].getFigura()!='*')&&(tablero[posI][posJ-1].getFigura()!='*')&&izquierda==true&&arriba==true){//

//izquierda

			if((tablero[posI][posJ-1].getColor()==col&&tablero[posI][posJ-1].getFigura()!=fig)){
				izquierdacolor=true;
			}else{
				izquierdacolor=false;
			}
			
			if((tablero[posI][posJ-1].getFigura()==fig&&tablero[posI][posJ-1].getColor()!=col)){
				izquierdafigura=true;
			}else{
				izquierdafigura=false;
			}
						

//arriba

			if((tablero[posI-1][posJ].getColor()==col&&tablero[posI-1][posJ].getFigura()!=fig)){
				arribacolor=true;
			}else{
				arribacolor=false;
			}
			
			
			if((tablero[posI-1][posJ].getFigura()==fig&&tablero[posI-1][posJ].getColor()!=col)){
				arribafigura=true;
			}else{
				arribafigura=false;
			}
//		

//decision


	if((izquierdacolor==true&&arribacolor==true)==true){
		return true;
	}else{
		if((izquierdafigura==true&&arribafigura==true)==true){
					return true;

		}else{
			if((izquierdafigura==true&&arribacolor==true)==true){
						return true;

			}else{
				if((izquierdacolor==true&&arribafigura==true)==true){
							return true;

				}else{
					return false;
				}
			}
		}
	}


//return true;
return false;


}


///		abajo					derecha						
if((tablero[posI+1][posJ].getFigura()!='*')&&(tablero[posI][posJ+1].getFigura()!='*')&&derecha==true&&abajo==true){//

//derecha

			if((tablero[posI][posJ+1].getColor()==col&&tablero[posI][posJ+1].getFigura()!=fig)){
				derechacolor=true;
			}else{
				derechacolor=false;
			}
			
			if((tablero[posI][posJ+1].getFigura()==fig&&tablero[posI][posJ+1].getColor()!=col)){
				derechafigura=true;
			}else{
				derechafigura=false;
			}
						

//abajo

			if((tablero[posI+1][posJ].getColor()==col&&tablero[posI+1][posJ].getFigura()!=fig)){
				abajocolor=true;
			}else{
				abajocolor=false;
			}
			
			
			if((tablero[posI+1][posJ].getFigura()==fig&&tablero[posI+1][posJ].getColor()!=col)){
				abajofigura=true;
			}else{
				abajofigura=false;
			}
//		

//decision


	if((derechacolor==true&&abajocolor==true)==true){
		return true;
	}else{
		if((derechacolor==true&&abajofigura==true)==true){
					return true;

		}else{
			if((derechafigura==true&&abajocolor==true)==true){
						return true;

			}else{
				if((derechafigura==true&&abajofigura==true)==true){
							return true;

				}else{
					return false;
				}
			}
		}
	}


//return true;
return false;

}

///		abajo								izq			
if((tablero[posI+1][posJ].getFigura()!='*')&&(tablero[posI][posJ-1].getFigura()!='*')&&izquierda==true&&abajo==true	){//&&arriba==false&&derecha==falsehgmcxjs


//izquierda

			if((tablero[posI][posJ-1].getColor()==col&&tablero[posI][posJ-1].getFigura()!=fig)){
				izquierdacolor=true;
			}else{
				izquierdacolor=false;
			}
			
			if((tablero[posI][posJ-1].getFigura()==fig&&tablero[posI][posJ-1].getColor()!=col)){
				izquierdafigura=true;
			}else{
				izquierdafigura=false;
			}
						

//abajo

			if((tablero[posI+1][posJ].getColor()==col&&tablero[posI+1][posJ].getFigura()!=fig)){
				abajocolor=true;
			}else{
				abajocolor=false;
			}
			
			
			if((tablero[posI+1][posJ].getFigura()==fig&&tablero[posI+1][posJ].getColor()!=col)){
				abajofigura=true;
			}else{
				abajofigura=false;
			}
//		

//decision


	if((izquierdacolor==true&&abajocolor==true)==true){
		return true;
	}else{
		if((izquierdafigura==true&&abajofigura==true)==true){
					return true;

		}else{
			if((izquierdafigura==true&&abajocolor==true)==true){
						return true;

			}else{
				if((izquierdacolor==true&&abajofigura==true)==true){
							return true;

				}else{
					return false;
				}
			}
		}
	}


//return true;
return false;

}







///		abajo		arriba									
if((tablero[posI+1][posJ].getFigura()!='*')&&(tablero[posI-1][posJ].getFigura()!='*')&&arriba==true&&abajo==true){//

return true;
}


///							derecha			izq			
if((tablero[posI][posJ+1].getFigura()!='*')&&(tablero[posI][posJ-1].getFigura()!='*')&&derecha==true&&izquierda==true){//

return true;
}




///		abajo											
if((tablero[posI+1][posJ].getFigura()!='*') &&(tablero[posI-1][posJ].getFigura()=='*')&&(tablero[posI][posJ+1].getFigura()=='*')&&(tablero[posI][posJ-1].getFigura()=='*')&&abajo==true){//

return true;
}


///				arriba									
if((tablero[posI-1][posJ].getFigura()!='*')&&(tablero[posI+1][posJ].getFigura()=='*')&&(tablero[posI][posJ+1].getFigura()=='*')&&(tablero[posI][posJ-1].getFigura()=='*')&&arriba==true){//

return true;
}

///							derecha						
if((tablero[posI][posJ+1].getFigura()!='*')&&(tablero[posI+1][posJ].getFigura()=='*')&&(tablero[posI-1][posJ].getFigura()=='*')&&(tablero[posI][posJ-1].getFigura()=='*')&&derecha==true){//

return true;
}

///										izq			
if((tablero[posI][posJ-1].getFigura()!='*')&&(tablero[posI+1][posJ].getFigura()=='*')&&(tablero[posI-1][posJ].getFigura()=='*')&&(tablero[posI][posJ+1].getFigura()=='*')&&izquierda==true){

return true;
}


return false;// si nada de las validaciones se dio retornar falso
	
}






void Partida::int_To_charpuntero(int x,int y,int num){
//metodo que hace comversion de tipos y ademas pinta en pantalla


  int number=num;
  stringstream strs;
  strs << number;//int to string
  string temp_str = strs.str();
  char* char_type = (char*) temp_str.c_str();// int to string to char*
  
  
  settextstyle(8,0,2);// 1 pequeño 2 mediano 3 grande
	setcolor(WHITE);//con este se le da el color a las letras
	setbkcolor(BROWN);

	outtextxy(x,y ,char_type);//"This is a test of int to char."

	setcolor(0);
}

Partida::~Partida()
{
}



