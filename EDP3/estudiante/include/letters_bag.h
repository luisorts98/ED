#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__
#include "Bag.h"
#include "letters_set.h"
#include <vector>


/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

using namespace std;

class LettersBag{

private:
Bag<char> letters;


public:

/**
 * @brief Constructor por defecto
 * Crea un LettersBag vacío.
 */
LettersBag();

/**
 * @brief Constructor cuyo parametro es un LetterSet &
 * Dado un LetterSet como argumento, este constructor debe rellenar la LettersBag con las 
 * letras que contiene el LertterSet, introduciendo cada letra el número de veces indicado 
 * por el campo LetterInfo::repetitions.
 * @param letterSet TDA LetterSer a persear.
 */

LettersBag(const LettersSet & letterSet);


/**
 * @brief Metodo para insertar una nueva letra en la bolsa de caracteres.
 * Se inserta el carácter usando el método add de la clase Bag.
 * @param l letra a añadir a la LetterBag
 */

void insertLetter(const char & l);

/**
 * @brief Metodo que nos pemite extraer una letra aleatoria de la bolsa de caracteres.
 * Usando el método get de Bag, se extrae una letra al azar y se elimina de la bolsa
 * @return char representa la letra extraida
 * @post letra extraida se ha eliminado de la bolsa
 */
char extractLetter();

/**
 * @brief Extrae un conjunto de letras
 * @param num numero de letras a extraer
 * @return lista con las letras extraidas aleatoramente
 * @post letras extraidas se han eliminado de la bolsa
 */
vector<char> extractLetters(int num);


/**
 * @brief Funcion para consultar el tamaño de LettersBag
 *  Indica el tamaño de la bolsa utilizando el método size de la clase Bag.
 * @return int con el tamaño de la bolsa
 */
unsigned int size() const;

/**
 * @brief Funcion para vaciar LetterBag
 * Usando el método clear de Bag se eliminan todos los caracteres de la bolsa.
 * @post Elimina todo el contenido de la LettersBag
 */
void clear();

/**
 * @brief Sobrecarga de los operadores de asignación.
 *  Copia los datos de un LettersBag dado como argumento al LettersBag usando el
 * operador de asignación. Para ello, se usa la sobrecarga del operador de
 * asignación de la clase Bag.
 * @param other Objeto de LettersBag del que se hará la copia
 * @return refernecia a this de esta forma el operador puede ser encadenado
 */
LettersBag & operator=(const LettersBag & other);

};
#endif
