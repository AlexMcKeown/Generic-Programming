#include "Mint.h"
Mint::Mint(int _character, int _p) // Mint
{
    p = _p; // Modulus
    setCharacter(_character);
}
int Mint::operator-(Mint otherCharacter)
{
    int num = 0;
    if (typeid(otherCharacter.getCharacter()).name() == typeid(int).name())
    {
        num = character - otherCharacter.getCharacter();

        if (num < 0)
        {
            num = p + (num % p);
        }
        else
        {
            num = num % p;
        }
    }
    else
    {
        std::cerr << "Error in \"operator-()\": Mint class was given a invalid datatype; " << typeid(otherCharacter.getCharacter()).name() << "\nPlease enter either a char or an integer" << std::endl;
        exit(EXIT_FAILURE);
    }

    return num;
}

void Mint::setCharacter(int _character)
{
    if (typeid(_character).name() == typeid(int).name())
    {
        if (_character >= 0 && _character <= (p - 1))
        {
            character = _character; // 0 to p-1 range character
        }
        else
        {
            std::cerr << "Error in \"setCharacter()\": Mint class was given an int outside of its 0 to p-1 range; " << _character << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        std::cerr << "Error in \"setCharacter()\": Mint class was given a invalid datatype; " << typeid(_character).name() << "\nPlease enter either a char or an integer" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int Mint::getCharacter()
{
    return character;
}
