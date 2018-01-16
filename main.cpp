/*
	Mi primer programa usando POO..
	
	transformar Numeros Romanos
	A numeros Naturales y viceversa ...

	@Autor = Armando Jose Rojas Querales

	@email = rojasarmando260@gmail.com
	
	Estudiante de Ingenieria de Sistemas del 4to Semestre 
	
	UNEFA
	Extension Turen - Municipio Portuguesa
	Septiembre - 2015

 */


#include <iostream>
#include "Menu.hpp"
#include "Transformador.hpp"


using namespace std; 

 
//Declara el Protipe para los modulos dentro del menu

/**
 * Modulo para La transformacion de Un Numero Romano en Natural
 */
string Romanos_Natural();

/**
 * Modulo para La transformacion de Un Numero Natural a Romano
 */
string Natural_Romanos();


int main(){

	cabezera(); // Armando Rojas - 2015
	char opcion = 'x'; //inicializar la variable que controla el bucle
	string resultado; 

	fondo();// color del fondo

	while ((opcion=menu()) != '3'){
		
		switch(opcion){
			case '1':  resultado = Natural_Romanos(); break;
			case '2':  resultado = Romanos_Natural(); break;
			default: resultado = ""; break;
		} // fin del case	

		if(resultado != "" ) imprimirResultado(&resultado);

	} // fin del while

	mensajeFinal(); // muestra mensaje para la despedida 
	return 0;
}// fin del main 


/**
 * Funciones empleadas como modulos
 */

string Romanos_Natural(){

	string cadena="1";  // asigna un valor por defecto a la cadena
	Transformador romano; 

	do{
		limpiar(); // limpiar pantalla 
		cout<<endl<<endl<<endl; 
		
		if (cadena == "FALSE") // si marca un error muestra mensaje 
			cout<<"\tError Solo numeros del I al MMMCMXCIX"<<endl;

		cout<<"\tIngresa el Numeros Romanos >";
		cin>>cadena; // obtener los datos 
		
		cadena = romano.validar_romano(cadena); //transforma la cadena 
		cout<<cadena<<endl; 


	}while (cadena == "FALSE"); // Si devuelve false se repite el proceso

	return cadena; 
}// fin 



string Natural_Romanos(){
	 int aux = 1; // asigna un valor a var auxiliar 
	 string validacion; // obtener los datos 
	 Transformador romano; // crea el objecto 

		do{
			limpiar(); 
			cout<<endl<<endl<<endl; 

			if (aux > 3999 or aux < 1)  // en caso de error 
				cout<<"\tError El Numero debe estar entre 1 y 9999"<<endl;
			
			cout<<"\tIngresa un Numero Natural >"; 
			cin>>validacion; //obtener los dato

			aux = romano.str_Numero(validacion);  // lo transforma a int 

			validacion = validacion + " = "+romano.numeros_romanos(aux); // los convierte a numero romano


			}while(aux < 1 or  aux > 9999); // repite si existe un error 


	return validacion; 	
}// fin 
