#include <sstream>
#include <string.h>

using namespace std;

class Transformador
{
public:
	/**
	 * Transforma un numero int a un Numero Romano 
	 * @param  x [int]
	 * @return numeroRomano  [string]
	 */
	string numeros_romanos(long unsigned int x);

	/**
	 * Transforma un Numero Romano (string) a un Numero natural (string)
	 * @param  cadena [string]
	 * @return  numero_natural [string]
	 * @return  "FALSE" en caso de Error [string]
	 */
	string validar_romano(string cadena);

	/**
	 * Obtiene el tamaño de un String 
	 * @param cadena [string]
	 * @return tamaño de un arreglo [int]
	 */

	 int size_array(string cadena); 
	
	/**
	 * Transforma un int en un string
	 * @param numero [int]
	 * @return [string]
	 */
	string str_Cadena(int numero); 

	/**
	 * Transforma un string en un int
	 * @param cadena [int]
	 * @return [string]
	 */
	int str_Numero(string cadena); 
	
};


 int Transformador::size_array(string cadena){
 	
 	const int longitud = 120; // tamaño maximo de un string
	char cadena2[longitud]; //declarar un array de tamaño maximo
	
	for (int i = 0; i < longitud;  ++i)cadena2[i] = cadena[i]; 
	
	int size = strlen(cadena2); // usar strlen() para obtener el tamaño
 	
 	return size;
 }


 string Transformador::str_Cadena(int numero){
  
	stringstream stream; // Instancia el objecto
	string cadena; // valor a devolver

	stream << numero; // asigna el numero al objecto
	cadena = stream.str(); // devuelve el valor int como string
	
	return cadena; 
 }


 int Transformador::str_Numero(string cadena){

	 int numero = atoi(cadena.c_str()); // transforma el string
	 if (cadena != str_Cadena(numero) ) numero=0; // evalua el cambio
 	 return numero;
 }

  string Transformador::validar_romano(string cadena){
 
 	bool error = false;
 	int max = size_array(cadena);
 	char minuscula[7]= {'i','v','x','l','c','d','m'};
 	char mayuscula[7]= {'I','V','X','L','C','D','M'};
 	
 	
 	for (int i = 0; i < max; ++i) {

		for (int k = 0; k < 7; ++k)
			if (cadena[i] == minuscula[k]) cadena[i] = mayuscula[k];

 	}
 	
 	
	for ( int i = 0; i < 9999; ++i){

		if (cadena == numeros_romanos(i)){
			error = true;
			cadena+=" = "+str_Cadena(i);
		 } 

	} 

			
	if (error == false) cadena="FALSE";
	return cadena;
 }


 string Transformador::numeros_romanos(long unsigned int x){
	string y=""; // inicializa el valor a devolver

	/*Dentro de Ciertos Arrays, los Tipos de Numeros Romanos */
	string aux[11]={"","I","II","III","IV","V","VI","VII","VIII","IX","X"}; // del 1 al 10
	string aux2[9]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"}; // de 10 en 10 desde el 10
	string aux3[10]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM",}; // de 100 en 100 hasta 900
	string aux4[3]={"M","MM","MMM"}; // de 1000 en 1000 

	// Debe ser mayor a 1 
	if (x<=0) y="NO ES UN NUMERO NATURAL";
	
	//del 3999 al ... 9999
	for (int i = 3; i < 10; ++i) if(x > 999+(i*1000) && x < 2000+(i*1000)) {
		// Asigna 2 rayas y un salto de linea 
		y+="--\n\t\t"+aux[i+1]+" "; // asigna segun el array
		x-=1000+(i*1000); // resta el valor X para iterar en los demas for 
	}
	
	
	/* 
		Verificar si x esta en intervalo del if, asignar letra, 
		restar valor a x
		y avanzar al proximo for 
	*/

	//del 1000 al 3999
	for (int i = 0; i < 3; ++i) 
		if(x > 999+(i*1000) && x < 2000+(i*1000))
	 	{ 
		
		y+=aux4[i]; 
		x-=1000+(i*1000);
		} 
	
	//del 100 al 999
	for (int i = 0; i < 10; ++i) 
		if(x > 99+(i*100) && x < 200+(i*100)) 
		{ 
			y+=aux3[i]; 
			x-=100+(i*100);
		} 
	
	//del 10 al 99
	for (int i = 0; i < 9; ++i) 
		if(x > 9+(i*10) && x < 20+(i*10)) 
		{ 
			y+=aux2[i]; x-=10+(i*10);
		} 	

	// del 1 al 10 
	
	if (x > 0 && x<11) 

			y += aux[x]; // numeros del 1 al 10
		
	return y;
}

