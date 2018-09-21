#include<iostream>
#include<string>

using namespace std;

struct Producto
{
    string nombre;
    int peso; // en gramos
    float precio_kg;
};

struct Compra
{
    static const int MAX = 10;
    Producto lista[MAX];
};

// funci�n para devolver los datos de un producto como un string
string productoToString(Producto a)
{
    string rta;
    rta = a.nombre + "\t\t" + to_string(a.peso) + "\t" + to_string(a.precio_kg);
    return rta;
}

// crea una variable de tipo Producto y la devuelve
Producto creaProducto(string nombre, int peso, float precio)
{
}

// incrementa el precio de cada producto en un k %
void incrementarPrecios(Compra & c, int k)
{
}

// muestra el listado de productos comprados
void listarCompra(const Compra & c)
{
}

// funci�n que devuelve el importe total de la compra (sinIVA) y su peso (en kgs)
void obtenerImporteYPeso(const Compra & c, float & precio, int & peso)
{
}

// funci�n que muestra el "ticket" de compra seg�n el formato sugerido
void mostrarTicketCompra(const Compra & c)
{
}

int main()
{
    const int TAM = 10;
    Producto actual;
    Compra mi_compra;
    float precio;
    int peso;
    string nombre;

    for(int i = 0; i < TAM; i++)
    {
        cin >> nombre >> peso >> precio;
        mi_compra.lista[i] = creaProducto(nombre, peso, precio);
    }

    // se muestra la lista de productos.
    cout << "\n ******** Prueba de funcion listarCompra ******** \n";
    listarCompra(mi_compra);

    // se muestra el importe total de la compra y el peso
    cout << "\n ******** Prueba de funcion obtenerImporteYPeso ******** \n";
    obtenerImporteYPeso(mi_compra, precio, peso);
    cout << "\nEl importe de la compra es: " << precio << ", su compra pesa:" 
		 << peso << " Kg. " << endl;

    // se muestra el ticket de la compra.
    cout << "\n ******** Prueba de la funcion mostrarTicketCompra ******** \n";
    mostrarTicketCompra(mi_compra);

    cout << "\n ******** Prueba de la funcion incrementarPrecio ********";
    incrementarPrecios(mi_compra, 10);
    cout << "\n ******** y listarCompra de nuevo   \t\t********\n\n";
    listarCompra(mi_compra);

    return(0);
}

