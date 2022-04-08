#ifndef WORDLE_H
#define WORDLE_H
#include "ZorkUL.h"

class wordle {
private:
    string word;
protected:

public:
    wordle(string word):word(word) {}  //Initializer list must be used
    string getWord();

    void loadWords();
};


#endif // WORDLE_H
