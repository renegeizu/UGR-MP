#include <iostream>
#include <imagen.h>
#include <fstream>

using namespace std;

const int TOPE = 257;

void leer(char *s){
   do{
      cin.getline(s, TOPE-1);
   }while (s[0]=='\0');
}

int main(){
   char arteASCII[4501], grises[TOPE], nombreImagen[TOPE], nombreArchivo[TOPE], nombre[TOPE];
   int cadenasFichero, tamanho = 0;
   Imagen origen;
   ifstream fentrada;
   ofstream fsalida;

   cout << "Introduce el Nombre y la Ruta de la Imagen de Entrada: ";
   leer(nombreImagen);
	
   if (!origen.leerImagen(nombreImagen)){
      cerr << "Error en la Lectura de " << nombreImagen << "\n";
      return 1;
   }

   cout << "Introduce el Nombre y la Ruta del Archivo de Entrada: ";
   leer(nombreArchivo);

   fentrada.open(nombreArchivo);

   if(fentrada){

      fentrada.ignore(256, 10);

      fentrada >> cadenasFichero;

      cout << "Introduce el Nombre para los Ficheros: ";
      leer(nombre);

      while (nombre[tamanho]!='\0'){
         tamanho++;
      }

      nombre[tamanho] = '0';
      nombre[tamanho+1] = '\0';

      for(int i = 1; i <= cadenasFichero; i++){
         nombre[tamanho] = i+'0';
         fsalida.open(nombre);
         fentrada >> grises;
         fsalida << "\nLa imagen en arte ASCII es:\n";
         if(origen.aArteASCII(grises, arteASCII, 4500))
            fsalida << arteASCII;
         else
            fsalida << "La Conversion no ha sido Posible" << endl;
         fsalida.close();
      }

      fentrada.close();
   }else{

      cerr << "Error en la Apertura del Archivo";

   }

}
