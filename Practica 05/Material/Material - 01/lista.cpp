#include <string>
#include <fstream>
#include "lista.h"

using namespace std;

/// Construye una lista vacia (0 elementos)
Lista::Lista(){

}


/**
* @brief Construye una lista a partir de un elemento
* @param valor el elemento a insertar en la lista
* 
* Construye una lista de tamaño 1 e inserta la datos @a valor 
*/
Lista::Lista(string valor){

}

void Lista::destruir(){

}  

void Lista::insertar(string valor){
	
}

string Lista::getCelda(int pos) const{
	
}

int Lista::longitud() const{
	
}

bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
			else {
				int i = 0;
				getline(fin,grises); //leer cadena de caracteres
				while (i < lineas)&&(fin)){
					if (grises != ""){
						insertar(grises);
						i++;
					}
					getline(fin,grises); //leer cadena de caracteres
				}
			}
		} else {
			return false;
		} 
		fin.close();
	}
	return true;
}
