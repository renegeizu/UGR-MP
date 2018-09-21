//lee imagenes/gio.txt y la convierte en ascii con los caracteres "@%#*+=-:. "
#include<iostream>
#include<imagen.h>

using namespace std;


const int MAXLONG = 1000000;

void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}

int main(){
    char grises[MAXLONG];
    char arteASCII[MAXLONG]; 
    char nombreImagen[MAXLONG];
    Imagen origen;

	cout << "Introduzca nombre de la imagen: ";
	leelinea(nombreImagen);

    // Leer la imagen gio.txt
    if (!origen.leerImagen(nombreImagen)){
		cerr << "error leyendo imagen" << nombreImagen << endl;
	   return 1;
    }
	
	cout << "Introduzca conjunto de caracteres para realizar la conversión: ";
	leelinea(grises);

	
    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, MAXLONG-1))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;  
	
}
