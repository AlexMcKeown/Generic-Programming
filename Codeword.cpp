#include "Codeword.h"
template <typename T, typename D>
Codeword<T, D>::Codeword(std::vector<T> _symbolVector, D _special)
{
    symbolVector = _symbolVector;
    setSpecial(_special); // either 'a' (Melt) or 0 (Mint)
}
template <typename T, typename D>
void Codeword<T, D>::setSpecial(D _special)
{
    if (typeid(_special).name() == typeid(int).name()) // If special is a int it can only be a Mint case
    {
        if (_special == 0) // 0 is the special keyword for Mint
        {
            special = _special;
        }
        else
        {
            std::cerr << "Error in \"setSpecial()\": Class Codeword is given an invalid integer; " << _special << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (typeid(_special).name() == typeid(char).name()) // If special is a char it can only be a Melt case
    {
        if (_special == 'a') // 'a' is the special keyword for Melt
        {
            special = _special;
        }
        else
        {
            std::cerr << "Error in \"setSpecial()\": Class Codeword is given an invalid char; " << _special << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        std::cerr << "Error in \"setSpecial()\": Class Codeword was given an invaild datatype; " << typeid(_special).name() << std::endl;
        exit(EXIT_FAILURE);
    }
}
template <typename T, typename D>
int Codeword<T, D>::weight()
{
    int num = 0;
    for (int i = 0; i < symbolVector.size(); i++)
    {
        if (special != symbolVector[i].getCharacter()) // if not 'a' or 0 add to the counter
        {
            num++;
        }
    }
    return num;
}
template <typename T, typename D>
int Codeword<T, D>::distance(std::vector<T> codeword) // Codeword is one row below Symbol vector
{
    int num = 0;
    for (int i = 0; i < symbolVector.size(); i++)
    {
        num += symbolVector[i] - codeword[i]; // uses the overloaded operator- from Symbol to produce the distance.
    }
    return num;
}
template <typename T, typename D>
void Codeword<T, D>::display()
{
    for (int i = 0; i < symbolVector.size(); i++)
    {
        std::cout << symbolVector[i].getCharacter() << " ";
    }
    std::cout << "Weight: " << weight() << std::endl;
}

template <typename T, typename D>
std::vector<T> Codeword<T, D>::getSymbolVector()
{
    return symbolVector;
}
