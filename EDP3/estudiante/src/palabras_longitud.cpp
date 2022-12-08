#include <iostream>
#include <fstream>
#include <dictionary.h>

using namespace std;

int main (int args, char* argv[]) {

    // Creamos un Dictionary a partir el fichero dado como primer argumento
    ifstream fichero;
    fichero.open(argv[1]);
    Dictionary dictionary;
    fichero >> dictionary;

    // Longitud de las palabras como segundo argumento
    int longitud = atoi(argv[2]);

    // Imprimimos en pantalla las palabras de dicha longitud
    vector<string> palabras = dictionary.wordsOfLength(longitud);
    cout << "Palabras de longitud " << longitud << endl;
    for (int i = 0; i < palabras.size(); ++i)
        cout << palabras[i] << endl;

}