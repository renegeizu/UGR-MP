/* Programa que calcula un círculo con centro en medio de dos círculos y radio la mitad de la distancia. 
	También calcula su área.
   
   Author: MP
   Módulo no definitivo (creado para ser modificado)

   Un ejemplo de ejecución es:
   	Introduzca un circulo en formato radio-(x,y): 3-(0,0)
   	Introduzca otro circulo: 4-(5,0)
   	El círculo que pasa por los dos centros es: 2.5-(2.5,0)
		Su area es: 19.63
**/

#include <iostream>
#include <cmath> 

using namespace std;

// Definición de las estructuras

struct Punto {
    double x; 
    double y; 
};

struct Circulo {
    Punto centro; 
    double radio; 
};

// Prototipos de las funciones

void EscribirPunto(const Punto &p);

Punto LeerPunto();

double DistanciaPuntos(const Punto &p1, const Punto &p2);

Punto PuntoMedio(const Punto &p1, const Punto &p2);

void EscribirCirculo(const Circulo &c);

Circulo LeerCirculo();

double AreaCirculo(const Circulo &c);

// Programa principal

int main(){
	Circulo c1,c2, c3;
   do{
		cout << "Introduzca un circulo en formato radio-(x,y): ";
		c1 = LeerCirculo();
		cout << "Introduzca otro circulo: ";
		c2 = LeerCirculo();
	}while(DistanciaPuntos(c1.centro,c2.centro) == 0);
	c3.centro = PuntoMedio(c1.centro, c2.centro);
	c3.radio = DistanciaPuntos(c1.centro, c2.centro)/2;
	cout << "El circulo que pasa por los dos centros es: ";
	EscribirCirculo(c3);
	cout << endl << "Su area es: " << AreaCirculo(c3) << endl;
}

// Implementación de las funciones

void EscribirPunto(const Punto &p){
	cout << "(" << p.x << "," << p.y << ")";
}

Punto LeerPunto(){
	Punto punto1;
	
	double contador = 0.1, conteo = 1, localizacion = 0, auxiliar;
	bool flag = true;
	auxiliar = cin.get();
	auxiliar = cin.get();
	while(auxiliar != ','){
		if(auxiliar != '.' && flag){
			contador *= 10;
		}else{
			flag = false;
		}
		if(auxiliar != '.'){
			localizacion += (auxiliar-48)*conteo;
			conteo *= 0.1;
		}
		auxiliar = cin.get();
	}
	punto1.x = localizacion*contador;
	contador = 0.1, conteo = 1, localizacion = 0, auxiliar;
	flag = true;
	auxiliar = cin.get();
	while(auxiliar != ')'){
		if(auxiliar != '.' && flag){
			contador *= 10;
		}else{
			flag = false;
		}
		if(auxiliar != '.'){
			localizacion += (auxiliar-48)*conteo;
			conteo *= 0.1;
		}
		auxiliar = cin.get();
	}
	punto1.y = localizacion;
	return punto1;
}

double DistanciaPuntos(const Punto &p1, const Punto &p2){
	return sqrt(pow(p1.x-p2.x, 2.0)+pow(p1.y-p2.y, 2.0));
}

Punto PuntoMedio(const Punto &p1, const Punto &p2){
	Punto punto2 = {((p1.x+p2.x)/2), ((p1.y+p2.y)/2)};
	return punto2;
}

void EscribirCirculo(const Circulo &p){
	cout << p.radio << "-(" << p.centro.x << "," << p.centro.y << ")";
}

Circulo LeerCirculo(){
	Circulo circulo1;
	double contador = 0.1, conteo = 1, radio = 0, auxiliar;
	bool flag = true;
	auxiliar = cin.get();
	while(auxiliar != '-'){
		if(auxiliar != '.' && flag){
			contador *= 10;
		}else{
			flag = false;
		}
		if(auxiliar != '.'){
			radio += (auxiliar-48)*conteo;
			conteo *= 0.1;
		}
		auxiliar = cin.get();
	}
	circulo1.radio = radio*contador;
	circulo1.centro = LeerPunto();
	return circulo1;
	//scanf("%d-(%d,%d)", radio, x, y);
}

double AreaCirculo(const Circulo &c){
	return 3.1416*pow(c.radio, 2.0); //3.1416 == M_PI
}

/* Fin: circulomedio.cpp */
