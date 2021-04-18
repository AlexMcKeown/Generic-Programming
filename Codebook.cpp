#include "Codebook.h"
template <typename T, typename D>
Codebook<T, D>::Codebook(std::vector<Codeword<T, D>> _codewordVector)
{
    codewordVector = _codewordVector;
}
template <typename T, typename D>
int Codebook<T, D>::minimumWeight()
{
    int num = 0;
    if (!codewordVector.empty())
    {
        num = codewordVector.back().weight(); // Initializing num to begin comparing operation
    }

    for (int i = 1; i < codewordVector.size(); i++) // Skip 0 index as special codeword is always weighted at 0
    {
        if (num > codewordVector[i].weight())
        {
            num = codewordVector[i].weight();
        }
    }
    return num;
}
template <typename T, typename D>
void Codebook<T, D>::calcDistance()
{
    distances.clear();
    if (codewordVector.size() > 1)
    {
        for (int i = 0; i < codewordVector.size(); i++)
        {
            for (int k = 0; k < codewordVector.size(); k++)
            { // Uses codewords distance function which uses the Symbol operator-()
                if (k != i)
                {
                    int num = codewordVector[i].distance(codewordVector[k].getSymbolVector());
                    distances.push_back(num);
                }
            }
        }
    }
    else
    {
        distances.push_back(0);
    }
}
template <typename T, typename D>
int Codebook<T, D>::minimumDistance()
{
    calcDistance();

    int num = 0;
    if (!distances.empty())
    {
        num = distances.front(); // Initializing num to begin comparing operation
    }

    for (int i = 0; i < distances.size(); i++)
    {
        if (num > distances[i])
        {
            num = distances[i];
        }
    }
    return num;
}
template <typename T, typename D>
void Codebook<T, D>::display()
{
    for (Codeword<T, D> c : codewordVector)
    {
        c.display();
    }
    std::cout << "The minimum weight is " << minimumWeight() << std::endl;
    std::cout << "The minimum distance is " << minimumDistance() << std::endl;
}
