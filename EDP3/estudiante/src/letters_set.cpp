#include "letters_set.h"

#include <iostream>
#include "letters_set.h"

using namespace std;

LettersSet::LettersSet () {

}

LettersSet::LettersSet (const LettersSet & other) {
    this->letters = other.letters;
}

bool LettersSet::insert (const pair<char, LetterInfo> & val) {
    
    bool insertado = letters.insert(val).second;
    return insertado;
}

bool LettersSet::erase (const char & key) {
   
    bool borrado = letters.erase(key);
    return borrado;
}

void LettersSet::clear () {
    letters.clear();
}

bool LettersSet::empty () const {
    return letters.empty();
}

unsigned int LettersSet::size () const {
    return letters.size();
}

int LettersSet::getScore (string word) {
    int score = 0;
    char letra;
    for (int i = 0; i < word.size(); ++i) {
        letra = toupper(word[i]);
        score += letters[letra].score;
    }
    return score;
}

LettersSet & LettersSet::operator= (const LettersSet & cl) {
    this->letters = cl.letters;
    return *this;
}

LetterInfo & LettersSet::operator[] (const char & val) {
    return letters[val];
}

ostream & operator<< (ostream & out, const LettersSet & cl) {
   
    for (LettersSet::const_iterator itr = cl.letters.begin(); itr != cl.letters.end(); ++itr) {

        out << (*itr).first << "\t" << (*itr).second.repeticiones << "\t" << (*itr).second.score << endl;
    }
    return out;

}

istream & operator>> (istream & is, LettersSet & cl) {
    char letra;
    LetterInfo datos;
    string cabecera;
    getline(is, cabecera);
    while (is) {
        is >> letra >> datos.repeticiones >> datos.score;
        pair<char, LetterInfo> par = make_pair(letra, datos);
        cl.insert(par);
    }
    return is;
}