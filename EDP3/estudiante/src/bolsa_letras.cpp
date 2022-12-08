#include <iostream>
#include <fstream>
#include <letters_set.h>
#include <letters_bag.h>

using namespace std;

int main (int args, char* argv[]) {

    // Creamos un LettersSet a partir el fichero dado como argumento
    ifstream fichero_letras;
    fichero_letras.open(argv[1]);
    LettersSet letras;
    fichero_letras >> letras;

    // Creamos un LettersBag que contenga las letras del LettersSet "letras"
    LettersBag bolsa(letras);

    // Imprimimos en pantalla los elementos de la bolsa, sacándolos de manera aleatoria
    while (bolsa.size() > 0) {
        cout << bolsa.extractLetter() << endl;
    }

}