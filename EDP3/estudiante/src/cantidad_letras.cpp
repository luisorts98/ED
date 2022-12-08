#include <iostream>
#include <fstream>
#include <letters_set.h>
#include <dictionary.h>

using namespace std;

int main (int args, char* argv[]) {

    // Creamos un Dictionary a partir del archivo dado como primer argumento
    ifstream fichero_diccionario;
    fichero_diccionario.open(argv[1]);
    Dictionary dictionary;
    fichero_diccionario >> dictionary;

    // Creamos un LettersSet a partir del archivo dado como segundo argumento
    ifstream fichero_letras;
    fichero_letras.open(argv[2]);
    LettersSet letras;
    fichero_letras >> letras;

    // Para cada letra del LettersSet, calculamos su número de ocurrencias en
    // el Dictionary y su frecuencia relativa, imprimiéndolos en pantalla
    double total = dictionary.getTotalLetters();
    double ocurrencias;
    double frecuencia;
    cout << "Letra\tFAbs.\tFrel." << endl;
    for (LettersSet::iterator itr = letras.begin(); itr != letras.end(); ++itr) {
        ocurrencias = dictionary.getOcurrences((*itr).first);
        frecuencia = ocurrencias / total;
        cout << (*itr).first << "\t" << ocurrencias << "\t" << frecuencia << endl;
    }

}