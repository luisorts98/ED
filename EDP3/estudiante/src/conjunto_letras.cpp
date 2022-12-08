#include <iostream>
#include <fstream>
#include <letters_set.h>

using namespace std;

int main (int args, char* argv[]) {

    // Creamos un LettersSet a partir del archivo dado como primer argumento
    ifstream fichero;
    fichero.open(argv[1]);
    LettersSet set = LettersSet();
    fichero >> set;

    // Palabra dada como segundo argumento
    string palabra = argv[2];

    // Imprimimos en pantalla cuántos puntos vale la palabra
    cout << set.getScore(palabra) << endl;

}