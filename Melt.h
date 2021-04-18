#ifndef MELT_H
#define MELT_H
#include <iostream>
#include <typeinfo>
class Melt
{
private:
    char character;
    int p; // given 26 when constructed
public:
    Melt(char _character); // Melt
    int operator-(Melt otherCharacter);
    void setCharacter(char _character);
    char getCharacter();
};
#endif
