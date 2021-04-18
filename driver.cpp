#include "generateValue.h"
#include <cctype>
#include <string.h>

#include "Melt.h"
#include "Mint.h"
#include "Codeword.h"
#include "Codeword.cpp"
#include "Codebook.h"
#include "Codebook.cpp"

int main(int argc, char *argv[])
{
    std::string str = "\nPlease format like so for \nMint: ./CFC Case Seed Length Size Modulus\nMelt: ./CFC Case Seed Length Size \nCase: 0 (Mint) or 1 (Melt) \nSeed, Length and Size: Positive integer\n(MINT ONLY) Modulus: Positive integer\n";
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++) // Validating Argument Parameters before use
        {
            for (int j = 0; j < strlen(argv[i]); j++)
            {
                if (isdigit(argv[i][j]) == 0) // Checks if it is a number | returns 0 if false
                {
                    std::cerr << "Error! Please use an integer! Invaild parameter given; " << argv[i] << str << std::endl;
                    exit(EXIT_FAILURE);
                }
            }

            if (i == 1) // Checks Case only
            {
                if (atoi(argv[i]) < 0 || atoi(argv[i]) > 1) // Check if case is NOT 0 or 1
                {
                    std::cerr << "Error! Please use an integer 0-1 for the case! Invaild parameter given; " << argv[i] << str << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            else if (i > 1) // Checks seed,length,size and mod if postive ints
            {
                if (atoi(argv[i]) < 1)
                {
                    std::cerr << "Error! Please use a positive integer for the seed,length,size and or modulus! Invaild parameter given; " << argv[i] << str << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    else
    {
        std::cerr << "Error! missing necessary command line parameters" << str << std::endl;
        exit(EXIT_FAILURE);
    }

    switch (atoi(argv[1]))
    {
    case 0: // Mint
        if (argc == 6)
        {

            const int seed = atoi(argv[2]);
            const int length = atoi(argv[3]); // The number of Symbols in each codeword
            const int size = atoi(argv[4]);   // The number of codewords in each codebook
            const int special = 0;
            const int modulus = atoi(argv[5]);
            std::vector<Mint> mintVector;                    // Stores collection of Symbols so that the can become codeword objects
            std::vector<Codeword<Mint, int>> codewordVector; // Stores collection of Codewords so that the  can become a codebook

            // The container contains a zero codeword with the m elements being all
            // "zero" in accordance with the element for the contained symbol
            for (int i = 0; i < length; i++)
            {
                Mint m1(special, modulus); // Creates mint object
                mintVector.push_back(m1);  // Adds mint object to collection of mints
            }
            Codeword<Mint, int> c2(mintVector, special); // Adds collection of mints to Codeword object plus the special character (0)
            codewordVector.push_back(c2);                // Adds Codeword object to collection of codeword
            mintVector.clear();

            for (int k = 0; k < (size - 1); k++) // Number of codeword in each codebook
            {
                for (int i = 0; i < length; i++) // Length of codeword
                {
                    Mint m2(generateMint(seed, modulus), modulus); // Creates mint object
                    mintVector.push_back(m2);
                }
                Codeword<Mint, int> c2(mintVector, special);
                codewordVector.push_back(c2); // Giving collection of mints to codeword
                mintVector.clear();
            }
            Codebook<Mint, int> codebook(codewordVector);
            codebook.display();
        }
        else if (argc > 6)
        {
            std::cerr << "Error! Mint has too many command line parameters" << str << std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            std::cerr << "Error! Mint is missing necessary command line parameters" << str << std::endl;
            exit(EXIT_FAILURE);
        }
        break;

    case 1: // Melt
        if (argc == 5)
        {
            const int seed = atoi(argv[2]);
            const int length = atoi(argv[3]); // The number of Symbols in each codeword
            const int size = atoi(argv[4]);   // The number of codewords in each codebook
            const char special = 'a';

            std::vector<Melt> meltVector;
            std::vector<Codeword<Melt, char>> codewordVector;

            // The container contains a zero codeword with the m elements being all
            // "zero" in accordance with the element for the contained melt
            for (int i = 0; i < length; i++)
            {
                Melt m1(special);         // Creates melt object
                meltVector.push_back(m1); // Adds melt object to collection of melts
            }
            Codeword<Melt, char> c2(meltVector, special); // Adds collection of melts to Codeword object
            codewordVector.push_back(c2);                 // Adds Codeword object to collection of codeword
            meltVector.clear();

            for (int k = 0; k < (size - 1); k++) // Number of codeword in each codebook
            {
                for (int i = 0; i < length; i++) // Length of codeword
                {
                    Melt m2(generateMelt(seed)); // Generate Melt Symbol
                    meltVector.push_back(m2);
                }
                Codeword<Melt, char> c2(meltVector, special);
                codewordVector.push_back(c2); // Giving collection of Symbols to codeword
                meltVector.clear();
            }
            Codebook<Melt, char> codebook(codewordVector);

            codebook.display();
        }
        else if (argc > 5)
        {
            std::cerr << "Error! Melt has too many command line parameters" << str << std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            std::cerr << "Error! Melt is missing necessary command line parameters" << str << std::endl;
            exit(EXIT_FAILURE);
        }
        break;

    default:
        std::cerr << "Error! Please choose 1 for Mint or 0 for Melt. For the Case value" << str << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
