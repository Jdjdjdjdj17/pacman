#include <iostream>
#include <TazoDorado.hpp>
using namespace std;

int main(int argc, char const *argv[])
{
    int   entero = 0;
    bool  boolenao = true;
    char  letra = 'A';
    float decimal = 0.5;

    // cout << "Tamaño Entero: " << sizeof(entero) << endl;
    // cout << "Tamaño Booleano: " << sizeof(boolenao) << endl;
    // cout << "Tamaño Char: " << sizeof(letra) << endl;
    // cout << "Tamaño FLoat: " << sizeof(decimal) << endl;
    // cout << "Tamaño Tazo: " << sizeof(TazoDorado) << endl;

    // TazoDorado tazo1;
    // TazoDorado tazo2;
    // TazoDorado tazos[10];
    // for(size_t i = 0;i < 10;i++){
    // cout << "Direccion Tazo" << i << ": " <<&tazos[i] << endl;
    // }

    //void* direccion = malloc(1);


/// C-----------------------------------------------------------------------------------------------
    TazoDorado* direccion;
    cout << "Direccion de direccion: " << &direccion << endl;
    direccion = (TazoDorado *) malloc(sizeof (TazoDorado));
    cout << "Direccion dinamica0: " << direccion << endl;
    cout << "Direccion dinamica1: " << direccion + 1 << endl;

    direccion -> Inicializar();
    cout << "Valor en direccion: " << direccion->Flotando() << endl;

    /// C++------------------------------------------------------------------------------------------
    TazoDorado *direccion2;
    direccion2 = new TazoDorado();

    cout << "Valor en direccion2: " << direccion2->Flotando() << endl;
    

    return 0;
}
