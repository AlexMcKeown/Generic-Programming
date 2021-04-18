#ifndef CODEWORD_H
#define CODEWORD_H
#include "Mint.h"
#include "Melt.h"
#include <vector>
#include <algorithm>
template <typename T, typename D> // D is either char or int
class Codeword
{
private:
    std::vector<T> symbolVector;
    D special;

public:
    Codeword();
    Codeword(std::vector<T> _symbolVector, D _special);
    void setSpecial(D _special);
    int weight();
    int distance(std::vector<T> codeword);
    void display();
    std::vector<T> getSymbolVector();
};
#endif
