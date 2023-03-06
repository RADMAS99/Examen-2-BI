#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

//a. Declaración de constantes globales:
const int daCedula = 1727288878;
const string daNombre = "David Andres Unaucho Arevalo";

//b. Definición de la estructura daCoordenada:
struct daCoordenada {
    int dacapacidadBelica;
    string dageolocalizacion;
    string dadetalleArsenal;
    daCoordenada* daizquierda;
    daCoordenada* daderecha;
};

//d. Creación de un árbol binario de búsqueda:
daCoordenada* insertarCoordenada(daCoordenada* raiz, int capacidadBelica, string geolocalizacion, string detalleArsenal) {
    if (raiz == nullptr) {
        raiz = new daCoordenada;
        raiz->dacapacidadBelica = capacidadBelica;
        raiz->dageolocalizacion = geolocalizacion;
        raiz->dadetalleArsenal = detalleArsenal;
        raiz->daizquierda = nullptr;
        raiz->daderecha = nullptr;
    }
    else if (capacidadBelica < raiz->dacapacidadBelica) {
        raiz->daizquierda = insertarCoordenada(raiz->daizquierda, capacidadBelica, geolocalizacion, detalleArsenal);
    }
    else {
        raiz->daderecha = insertarCoordenada(raiz->daderecha, capacidadBelica, geolocalizacion, detalleArsenal);
    }
    return raiz;
}

//c. Lectura del archivo de texto con las coordenadas:
void  leerArchivoCoordenadas( string nombreArchivo) 
{
    ifstream archivo(nombreArchivo.c_str());
    string linea;

    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) 
        {
            int porcentaje = 0;
            cout << "Cargando: ";
            while (porcentaje <= 100) 
            {
                cout << porcentaje << "% ";
                porcentaje++;
                Sleep(10); 
            }
            cout << endl;
            cout << "Coordenadas leídas: " << linea << endl;
        }
        archivo.close();
    }
    else 
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main() {
    string nombreArchivo ="Listas/Coordenadas_Ucranianas.txt";
    leerArchivoCoordenadas(nombreArchivo);
return 0;
}



