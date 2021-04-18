#ifndef MINT_H
#define MINT_H
#include <iostream>
#include <typeinfo>
class Mint
{
private:
    int character;
    int p; // Mint's modulus i.e (0 to p-1 range)
public:
    Mint();
    Mint(int _character, int _p); // Mint
    int operator-(Mint otherCharacter);
    void setCharacter(int _character);
    int getCharacter();
};
#endif
