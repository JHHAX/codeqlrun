	/* Nombre del programa: primera_parteobligatoria_entregable.c
	 * Descripción: programa que abre un fichero y ejecuta la opción que se elija del menú
	 * @return -> la opción que has elegido ejecutada y en caso de que el archivo no se abra devuelve "Error al abrir este archivo".
	 * @autor: Pablo López López
	 * @date: incio--> 12/04/2022 || finalización-->27/04/2022
	 * @version: 1.1
	 */

	#include <stdio.h>
	#include <stdlib.h> 				//Bibliotecas introducidas
	#include <stdbool.h> 				//Bibliotecas para el bool
	#include <string.h> 				//Biblioteca de string (para carácteres largos)
	#include <ctype.h>					//Biblioteca para comprobar para verificar si es alfanumérico.


	int SolicitarOpcionMenu();
	void SeleccionarOpcion(int);
	int ContarCaracteres(FILE *);
	int NumeroTotalFilas(FILE *);
	int FilaMasLarga(FILE *);
										//funciones incializadas y ya funcionales comprobadas

	int main(){
		int opcion=0;
		
		do{
			SolicitarOpcionMenu();
			SolicitarOpcionMenu(opcion);
		}
		while(opcion!=0||opcion!=1||opcion!=2||opcion!=3);
										//repite el do mientras que la opción que ponga sea esos números, en el caso del 0 como es salir no lo repetiría más
		return 1;						//Poner en todos los int para evitar el warning aun que no hace falta de normal
										//Fin del programa después de haber terminado el while o haber salido por otro medio
	}

	/* Nombre:main
	 * Descripción:Función principal que hace un "do while" hasta que opcion sea diferente de 1,2,3 o 0
	 *
	 * @param: opcion--> sirve para inicializarlo al utilizarse después
	 * @autor: Pablo López López
	 * @date: 14/04/2022
	 */

	int SolicitarOpcionMenu(){
		int opcion;
			printf("\nElige la opción que quieras ejecutar:\n"
				"***************	*\n"
				"* 1. Número total de carácteres alfanuméricos	*\n"
				"*                                            	*\n"
				"* 2. Número total de filas, sin cabecera       *\n"
				"*                                            	*\n"
				"* 3. Dice la fila más larga                  	*\n"
				"*   										  	*\n"
				"* 0. Salir                                   	*\n"
				"***************	*\n");
			printf("Introduzca una opción: ");
			fflush(stdin);
            scanf("%d", &opcion);
                                    // Validamos la opción
            while (opcion < 0 || opcion > 3){
            printf("Opción no válida.\n");
            printf("Introduzca una opción: ");
            fflush(stdin);
            scanf("%d", &opcion);
            }
    return opcion;
	}


	/* Nombre: SolicitarOpcionMenu
 	* Descripción: Imprime por pantalla el menú con las opciones que puedes elegir con la función SeleccionarOpcion.
 	*
 	* @autor: Pablo López López
 	* @date: 15/04/2022
 	*/

	void SeleccionarOpcion(int opcion){
										// Declaramos la variable fichero.
    	FILE *fichero;
    									// Declaramos la variable contador.
    	int contador;
    									// Declaramos la variable numeroFilas.
    	int NumeroFilas;
    									// Declaramos la variable filaMasLarga.
    	int FilaMasLarga;	
    									// Abrimos el fichero.
    	fichero = fopen("DatosTelefonosMoviles.csv", "r");
    									// Comprobamos que el fichero se ha abierto correctamente
  										//Ejecutamos la ópcion que seleccionemos.
    	switch(opcion){
    		case 1:
				if(fichero==NULL){
					printf("Error al abrir el archivo DatosTelefonosMoviles.csv\n");//si el archivo no se abre (==NULL) se ejecuta este printf
				}
				else{
					                                                            	//este caso es si se abre, por lo que hay que poner la función que se va a hacer
					contador = ContarCaracteres(fichero);                           //No haría falta poner int ya que es una llamada  a una función		
    		    	if(fclose(fichero)==0){                                         //Este 0 en las siguientes funciones de fclose es NULL y al ser fclose devuelve 0 si se hace y devulve un error u otra cosa si no se hace
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}
				else{
					printf("\nNo se ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}
				break;
    		case 2:
    	    	if(fichero==NULL){
					printf("Error al abrir el archivo DatosTelefonosMoviles.csv\n");//si el archivo no se abre (==NULL) se ejecuta este printf
				}
				else{	                                                            //este caso es si se abre, por lo que hay que poner la función que se va a hacer
					NumeroFilas = numeroTotalFilas(fichero);
    				if(fclose(fichero)==0){                                         //Este 0 en las siguientes funciones de fclose es NULL y al ser fclose devuelve 0 si se hace y devulve un error u otra cosa si no se hace
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}
				else{
				printf("\nNo se ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}
				break;
    		case 3:
    	    	if(fichero==NULL){
					printf("Error al abrir el archivo DatosTelefonosMoviles.csv\n");//si el archivo no se abre (==NULL) se ejecuta este printf
				}
				else{   
					                                                            //este caso es si se abre, por lo que hay que poner la función que se va a hacer
					FilaMasLarga = filaMasLarga(fichero);
    				if(fclose(fichero)==0){                                         //Este 0 en las siguientes funciones de fclose es NULL y al ser fclose devuelve 0 si se hace y devulve un error u otra cosa si no se hace
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}
				else{
					printf("\nNo se ha cerrado el archivo DatosTelefonosMoviles.csv correctamente\n");
				}
				break;

    		case 0:
				if(fclose(fichero)==0){
					printf("\nSe ha cerrado el archivo DatosTelefonosMoviles.csv correctamente, vaya al destino del archivo inicial y compruebe que está todo en orden\n");
				}
				else{
					printf("\nNo se ha cerrado el archivo DatosTelefonosMovilesL.csv correctamente\n");
				}
        		break;
    	}
    	//Cerramos el fichero una vez más.
    	fclose(fichero);
	}

	/*
 	* Función que cuenta los caracteres alfanuméricos
 	* @param fichero
 	* @return contador
 	*/

	int contarCaracteres(FILE *fichero){
                            // Declaramos la variable contador
    	int contador = 0;
                            // Declaramos la variable caracter
    	char caracter;
                            // Declaramos la variable salir
    	int salir = 0;
                            // Mientras no se llegue al final del fichero
    	while (!salir){
                            // Leemos el caracter
        	caracter = fgetc(fichero);
                            // Comprobamos que no se ha llegado al final del fichero
        	if (caracter != EOF){
                            // Comprobamos que el caracter es alfanumérico
            	if (isalnum(caracter)){
                            // Incrementamos el contador
                contador++;
            	}
        	}
        	else{
            	// Salimos del bucle
            	salir = 1;
        	}
    	}
    	return contador;
	}

	/*
 	* Función que cuenta el número de filas
 	* @param fichero: fichero a leer
 	* @return numeroFilas: número de filas
 	*/

	int NumeroTotalFilas(FILE *fichero){
		int LineaActual = 0;
		char PunteroDeLinea;
		//variables

		PunteroDeLinea=fgetc(fichero);//Lectura adelantada
		while(!feof(fichero)){
			//Se repite el bucle del while hasta que sea el final del fichero
			if(PunteroDeLinea=='\n'){
				LineaActual ++;//Al detectar el PunteroDeLinea un salto de línea suma a la línea actual uno
			}
			PunteroDeLinea=fgetc(fichero);
		}
		printf("\nHas elegido filas totales:\n. El archivo tiene %d líneas\n\n", LineaActual);//Al acabar el bucle imprime el número de líneas contadas
		return 1;
	}

	/*
 	* Función que cuenta la fila más larga
 	* @param fichero: Fichero en el que se buscará la fila más larga
 	* @return filaMasLarga: Número de la fila más larga
 	*/

	int FilaMasLarga(FILE *fichero){
		char CaracterActual;
		int Lector=0;
		int CaracteresDeFilaMasLarga=0;
		int CaracteresDeFilaActual=0;
		int FilaContada = 0;
		int FilaGanadora;
		//Variables

		CaracterActual=fgetc(fichero);                                     //Lectura adelantada

 		while(!feof(fichero)){	                                            //Repite el while hasta el final del fichero
			if(CaracterActual!='\n'){
				Lector++;                                               	//Si el CaracterActual es distinto de un salto de línea suma 1 al Lector
			}
			else{
				FilaContada++;                                              //Al no ser salto de línea pasa de línea y suma uno a esta variable
				CaracteresDeFilaActual = Lector - 1;                        //Al ser salto de línea guardamos los carácteres de la línea actual en la variable CaracteresDeFilaActual y restamos 1 que es el salto de línea que también se ha contado
				if(CaracteresDeFilaActual>CaracteresDeFilaMasLarga){        //Al comparar los caracteres de la línea actual con los de la más larga si estos son más se hace las siguientes funciones
					FilaGanadora = FilaContada;                             //Al ser más los caracteres de la fila actual, esta se guarda como FilaGanadora siendo la que más carácteres tendría hasta el momento 
					CaracteresDeFilaMasLarga = CaracteresDeFilaActual;      //Como también queremos guardas los carácteres de la fila actual para que los muestre despúes, se igualan a CaracteresFilaMasLarga para así no perderlos
				}
				Lector=0;                                                   //Lo igualo a 0 para que así solo cuente los carácteres de cada fila y no de todo el fichero
			}

			CaracterActual=fgetc(fichero);
 		}
		printf("\nHas elegido la fila más larga:\nLa fila más larga es la %d y tiene %d caracteres\n\n",FilaGanadora,CaracteresDeFilaMasLarga);//Una vez terminado el while sale por pantalla el printf que dice la fila más larga con sus respectivos carácteres
		return 1;
	}
