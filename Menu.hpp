#include <iostream>
#include <stdlib.h>

using namespace std; 

//limpiar pantalla solo en windows -- Linux se usa clear 
#define limpiar() system("cls")

// color de fondo solo en windows 
#define fondo() system("color 4f"); 
#define fondoAzul() system("color 1f"); 

// pausar pantalla -- solo windows 
#define pausa() system("pause")

#define cabezera() system("title Armando Rojas - 2015")


/**
 * Funcion para dibujar el menu
 * return char con la opcion correspondiente 
 */

char menu(){
		string opcion; // var de control

		limpiar(); 
		cout<<endl<<endl<<endl; // 3 saltos de linea
		cout<<"                       ########                        "<<endl;
		cout<<"                       # MENU #                        "<<endl;
		cout<<"                       ########                        "<<endl<<endl;

		cout<<"   1.. Convertir de Numeros Arabigos a Numeros Romanos"<<endl;
		cout<<"   2.. Convertir de Numeros Romanos a Numeros Arabigos"<<endl;
		cout<<"   3.. Finalizar Programa                             "<<endl;
		cout<<"      Escribe La Opcion y Presiona ENTER : "; 
		cin>>opcion;

		/*Validar la opcion */
		if (opcion== "1") return '1';
		else if (opcion== "2") return '2';
		else if (opcion== "3") return '3';
		else return '4';

}

void imprimirResultado(string  *validacion){

	limpiar(); // limpiar pantalla 
	cout<<endl<<endl<<endl;
	cout<<"\n\n\n\tResultado........"<<endl<<endl;
	cout<<"\t\t"<<*validacion<<endl<<endl<<endl;

	pausa(); // pausa la pantalla
	
}

void mensajeFinal(){

	limpiar();
	fondoAzul(); 

	cout<<endl<<endl<<endl; // 3 saltos de linea
	cout<<"\t# Numeros Romanos C++...."<<endl<<endl;
	cout<<"\t# Armando Rojas"<<endl<<endl;
	cout<<"\t# Correo : armando.develop@gmail.com "<<endl<<endl;
	cout<<"\t# UNEFA - Extension Turen "<<endl<<endl;
	cout<<"\t# Ingenieria de Sistema IV Semestre - 2015 "<<endl<<endl<<endl<<endl;
	pausa();

}






