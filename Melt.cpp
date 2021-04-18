#include "Melt.h"
Melt::Melt(char _character) // Melt
{
    p = 26; // 26 distinct characters in alphbet
    setCharacter(_character);
}

int Melt::operator-(Melt otherCharacter)
{
    int num = 0;
    if (typeid(otherCharacter.getCharacter()).name() == typeid(char).name())
    {
        if (character != otherCharacter.getCharacter())
        {
            num = 1;
        }
    }
    else
    {
        std::cerr << "Error in \"operator-()\": Melt class was given a invalid datatype; " << typeid(otherCharacter.getCharacter()).name() << "\nPlease enter either a char or an integer" << std::endl;
        exit(EXIT_FAILURE);
    }

    return num;
}
void Melt::setCharacter(char _character)
{

    if (typeid(_character).name() == typeid(char).name())
    {
        if (_character >= 'a' && _character <= 'z')
        {
            character = _character;
        }
        else
        {
            std::cerr << "Error in \"setCharacter()\": Melt class was given a char outside of its a-z range; " << _character << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        std::cerr << "Error in \"setCharacter()\": Melt class was given a invalid datatype; " << typeid(_character).name() << "\nPlease enter either a char or an integer" << std::endl;
        exit(EXIT_FAILURE);
    }
}

char Melt::getCharacter()
{
    return character;
}
