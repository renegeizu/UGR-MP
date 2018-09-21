#include <iostream>
#include <punto.h>
#include <cmath>

using namespace std;

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
