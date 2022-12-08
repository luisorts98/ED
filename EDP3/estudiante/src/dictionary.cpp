#include "dictionary.h"
#include <iostream>
#include <fstream>

using namespace std;
Dictionary::Dictionary()
{
}

Dictionary::Dictionary(const Dictionary & other)
{
    words = other.words;
}

bool Dictionary::exists(const string & val) const
{

    return words.find(val) != words.end();
}

bool Dictionary::insert(const string & val)
{
    bool insertado = (words.insert(val)).second;
    return insertado;
}


bool Dictionary::erase(const string & val)
{
    bool borrado = words.erase(val);
    return borrado;
}

void Dictionary::clear()
{
    words.clear();
}

bool Dictionary::empty() const
{
    return words.empty();
}

unsigned int Dictionary::size() const
{
    return words.size();
}

int Dictionary::getOcurrences(const char c){
  iterator it;
  int ocurrences = 0;
    for (it = words.begin(); it != words.end(); ++it){
        for (int i = 0; i < (*it).size(); ++i){
        if (toupper((*it)[i]) == toupper(c)){
            ocurrences++;
        }
        }
    }
    return ocurrences;
}

int Dictionary::getTotalLetters(){
    iterator it;
    int total = 0;
        for (it = words.begin(); it != words.end(); ++it){
            total += (*it).size();
        }
        return total;

}

vector<string> Dictionary::wordsOfLength(int length){
    iterator it;
    vector<string> wordsOfLength;
        for (it = words.begin(); it != words.end(); ++it){
            if ((*it).size() == length){
                wordsOfLength.push_back(*it);
            }
        }
        return wordsOfLength;
}


 ostream& operator<<(ostream & os, const Dictionary & dic) {
    for (Dictionary::const_iterator itr = dic.words.begin(); itr != dic.words.end(); ++itr) {
        os << (*itr) << endl;
    }
    return os;
}

istream& operator>> (istream & is, Dictionary & dic) {
    string palabra;
    while (is) {
        is >> palabra;
        if (palabra.size() != 1)
            dic.insert(palabra);
    }
    return is;
}   