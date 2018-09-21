#include <iostream>
#include <imagen.h>

using namespace std;

const int TOPE = 257;

void leer(char *s){
	do{
		cin.getline(s, TOPE-1);
	}while (s[0]=='\0');
}

int main(){
	char arteASCII[4501];
	char grises[TOPE];
	char nombre[TOPE];
   Imagen origen;

	cout << "Introduce el Nombre y la Ruta de la Imagen de Entrada: ";
	leer(nombre);
	
	if (!origen.leerImagen(nombre)){
		cerr << "Error en la Lectura de " << nombre << "\n";
		return 1;
	}

	cout << "Introduce el Conjunto de Caracteres: ";
	leer(grises);

	cout << "\nLa imagen en arte ASCII es:\n";
	if(origen.aArteASCII(grises, arteASCII, 4500))
		cout << arteASCII;
	else
		cout << "La conversión no ha sido posible" << endl;
}
