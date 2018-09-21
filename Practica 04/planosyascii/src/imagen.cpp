#include <cstring>
#include <byte.h>
#include <imagen.h>
#include <pgm.h>

using namespace std;

Imagen::Imagen(){
   nfilas = 0;
   ncolumnas = 0;
}
   
Imagen::Imagen(int filas, int columnas){
   nfilas = filas;
   ncolumnas = columnas;	
   for(int i = 0; i < nfilas*ncolumnas; i++){
      datos[i] = 0;
   }
}
   
void Imagen::crear(int filas, int columnas){
   nfilas = filas;
   ncolumnas = columnas;
   for(int i = 0; i < nfilas*ncolumnas; i++){
      datos[i] = 0;
   }
}
   
int Imagen::filas(){
   return nfilas;
}

int Imagen::columnas(){
   return ncolumnas;
}
   
void Imagen::set(int y, int x, byte v){
   datos[y*ncolumnas+x] = v;
}
   
byte Imagen::get(int y, int x){
   return datos[y*ncolumnas+x];
}
   
void Imagen::setPos(int i, byte v){
   datos[i] = v;
}
   
byte Imagen::getPos(int i){
   return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
   bool flag = false;
   TipoImagen tipo = infoPGM(nombreFichero, nfilas, ncolumnas);
   if((tipo == IMG_PGM_BINARIO) && ((nfilas*ncolumnas) < MAXPIXELS)){
      flag = leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
   }else if((tipo == IMG_PGM_TEXTO) && ((nfilas*ncolumnas) < MAXPIXELS)){
      flag = leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
   }	
   return flag;
}
   
bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
   bool flag = false;	
   if(esBinario)
      flag = escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
   else
      flag = escribirPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
   return flag;
}

Imagen Imagen::plano(int k){
   Imagen img(nfilas, ncolumnas);
   byte aux;	
   for(int i = 0; i < nfilas*ncolumnas; i++){
      aux = img.getPos(i);
      if(getbit(datos[i], k)){
         on(aux, 7);
      }else{
	 off(aux, 7);
      }
      img.setPos(i, aux);
   }
   return img;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
   int cardinal = 0, contadorRead = 0, aux = 0, contadorWrite = 0;
   bool flag = (nfilas*ncolumnas) < maxlong;	
   while (grises[cardinal]!='\0'){
      cardinal++;
   }	
   while(contadorRead < nfilas*ncolumnas && contadorWrite < maxlong){
      if(contadorRead%ncolumnas == 0 && contadorRead >= ncolumnas){
         arteASCII[contadorWrite] = 10;
	 contadorWrite++;
      }
      aux = datos[contadorRead];
      arteASCII[contadorWrite] = grises[aux*cardinal/256];
      contadorRead++;
      contadorWrite++;
   }	
   if(contadorWrite+1 < maxlong){
      arteASCII[contadorWrite] = 10;		
      arteASCII[contadorWrite+1] = '\0';
   }	
   return flag;
}
