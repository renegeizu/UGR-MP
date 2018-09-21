// Lee la imagen imagenes/giotexto.pgm y extrae el plano 6 en plano6.txt y el 
// plano 0 en plano.txt
#include<iostream>
#include<imagen.h>

using namespace std;

int main(){

    Imagen origen, plano;

	// Leer la imagen giotexto.pgm
	if (!origen.leerImagen("imagenes/giotexto.pgm")){
		cerr << "error leyendo imagenes/giotexto.pgm\n";
		return 1;
	}
	
	plano = origen.plano(6);
  	
	// Guardar la imagen plano en el fichero plano6.txt
	if (plano.escribirImagen("plano6.txt", false)){
		// si todo va bien
		cout << "plano6.txt guardado correctamente \n";
		cout << "usa: display plano6.txt para ver el resultado\n";
	} else { // si error
		cerr << "Error guardando la imagen plano6.txt\n";
		return 1;
	}	
	
	plano = origen.plano(0);
	
	// Guardar la imagen plano en el fichero plano0.txt
	if (plano.escribirImagen("plano0.txt", false)){
		// si todo va bien
		cout << "plano0.txt guardado correctamente \n";
		cout << "usa: display plano0.txt para ver el resultado\n";
	} else { // si error
		cerr << "Error guardando la imagen plano0.txt\n";
		return 1;
	}	

	return 0;
}
