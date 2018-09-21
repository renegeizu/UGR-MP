#include <iostream>

using namespace std;

struct Instante{
	int horas, minutos, segundos;
};

int convertirASegundos(const Instante &a){
	return (a.horas*3600)+(a.minutos*60)+(a.segundos);
}

Instante obtenerNuevoTiempo(Instante &b, int segundos){
	Instante a = b;

	a.segundos+=segundos;

	if(a.segundos>59){
		a.minutos+=a.segundos/60;
		a.segundos=a.segundos%60;
	}

	if(a.minutos>59){
		a.horas+=a.minutos/60;
		a.minutos=a.minutos%60;
	}

	if(a.horas>23){
		cerr << "Hay mas de 23 horas" << endl;
		return null;
	}else
		return a;
 
}

bool esPosterior(const Instante &a, const Instante &b){
	if(convertirASegundos(a) < convertirASegundos(b))
		return true;
	else
		return false;
}

int main(){
	Instante insA = {0, 45, 59};	
	Instante insB = {20, 59, 59};

	if(esPosterior(insA, insB))
		cout << "El segundo instante es mayor" << endl;
	else
		cout << "El primer instante es mayor" << endl;

	cout << "El primer instante en segs: " << convertirASegundos(insA) << endl;
	cout << "El segundo instante en segs: " << convertirASegundos(insB) << endl;

	Instante insC = obtenerNuevoTiempo(insA, 30);

	cout << "El nuevo insA en segs: " << convertirASegundos(insA) << endl;

	return 0;
}
