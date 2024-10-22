#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int   entero = 0;
    bool  boolenao = true;
    char  letra = 'A';
    float decimal = 0.5;

    cout << "Tamaño Entero: " << sizeof(entero) << endl;
    cout << "Tamaño Booleano: " << sizeof(boolenao) << endl;
    cout << "Tamaño Char: " << sizeof(letra) << endl;
    cout << "Tamaño FLoat: " << sizeof(decimal) << endl;

    return 0;
}
