#include <string>
#include <fstream>
#include <lista.h>

using namespace std;

Lista::Lista(){
	cabecera = NULL;
}
   
Lista::Lista(string valor){
	cabecera = new Celda;
		cabecera->datos = valor;
		cabecera->siguiente = NULL;
}
	

void Lista::destruir(){
	Celda* borra;
		while(cabecera != NULL){
			borra = cabecera;
			cabecera = cabecera->siguiente;
			delete borra;
		}
}  

void Lista::insertar(string valor){
	Celda* nueva = new Celda;
	nueva->datos = valor;
	nueva->siguiente = NULL;
	
	if(!cabecera){
		cabecera = nueva;
	}else{
		Celda* aux = cabecera;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nueva;
	}
		
}

string Lista::getCelda(int pos) const{
	string valor;
		int contador = 0;	
		Celda* aux = cabecera;	
		while(contador < pos && aux){
			aux = aux->siguiente;
			contador++;	
		}
	
	if(aux != NULL){
		valor = aux->datos;
	}

	return valor;
}

int Lista::longitud() const{
	
	int contador = 0;
	Celda* aux;

	aux = cabecera;

	while(aux != NULL){
		aux = aux->siguiente;
		contador++;
	}

	return contador;

}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion 
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura 
 * 
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda 
 * en la lista. La función debe asegurarse de que la estructura sigue un patron 
 * determinado, y se ha de crear la lista con el numero de elementos que contenga. 
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises);
		fin >> lineas;
		getline(fin,grises);
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises);
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises);
			}
		}
		fin.close();
	}
	return true;
}
