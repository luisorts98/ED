#include "letters_bag.h"
#include "letters_set.h"
#include <iostream>
#include <fstream>
#include "Bag.h"
using namespace std;

LettersBag::LettersBag()
{
}

LettersBag::LettersBag (const LettersSet & letterSet) { //recorrer con const iterator
    for (LettersSet::const_iterator itr = letterSet.begin(); itr != letterSet.end(); ++itr) {
        int rep = (*itr).second.repeticiones;
        for (int i = 0; i < rep; ++i) {

            letters.add((*itr).first);
        }
    }
}

void LettersBag::insertLetter(const char & l)
{
    letters.add(l);
}


char LettersBag::extractLetter()
{
    return letters.get();
}

vector<char> LettersBag::extractLetters(int num)
{
    vector<char> conjuntoletras;
    for (int i = 0; i < num; i++)
    {
        conjuntoletras.push_back(letters.get());
    }
    return conjuntoletras;
}



unsigned int LettersBag::size() const
{
    return letters.size();
}

void LettersBag::clear(){
    letters.clear();
}

LettersBag& LettersBag::operator=(const LettersBag &other)
{
    letters = other.letters;
    return *this;
}

       