#include <iostream>
#include <stdio.h>
#include "byte.h"
#include <cstring>

using namespace std;

void on(byte &b, int pos){
   unsigned char mask = 1 << pos;
   b = mask | b;
}

void off(byte &b, int pos){
   unsigned char mask = 1 << pos;
   b = ~mask & b;
}

bool getbit(byte b, int pos){
   unsigned char mask = 1 << pos;
   return (b & mask);
}

void print(byte b){
   for(int i = 7; i >= 0; i--){
      printf("%d",((b & (1<<i))>>i));
   }
}

void encender(byte &b){
   b = 255;
}

void apagar(byte &b){
   b = 0;
}

void asignar(byte &b, const bool v[]){
   for(int i = 0; i < 8; i++){
      if(v[i]){
         on(b, i);
      }else{
         off(b, i);
      }
   }
}

void volcar(byte b, bool v[]){
   for(int i = 0; i < 8; i++){
      v[i] = getbit(b, i);
   }
}

void encendidos(byte b, int posic[], int &cuantos){
   cuantos = 0;
   for(int i = 0; i < 8; i++){
      if(getbit(b, i)){
         posic[cuantos] = i;
	 cuantos++;
      }
   }
}

/*string byteToString(byte b){
	string cadena = "";
	for(int i = 7; i >= 0; i--){
		if(get(b, i)){
			cadena.push_back('1');
		}else{
			cadena.push_back('0');
		}
	}
	return cadena;
}*/
