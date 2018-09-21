#include <iostream>
#include <cmath> 
#include <circulo.h>

using namespace std;

void EscribirCirculo(const Circulo &p){
	cout << p.radio << "-";
	EscribirPunto(p.centro);
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
}

double AreaCirculo(const Circulo &c){
	return 3.1416*pow(c.radio, 2.0);
}
