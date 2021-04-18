#ifndef CODEBOOK_H
#define CODEBOOK_H
#include "Codeword.h"
template <typename T, typename D>
class Codebook
{
private:
    std::vector<Codeword<T, D>> codewordVector;
    std::vector<int> distances; // Stores all the distances of codewords

public:
    Codebook(std::vector<Codeword<T, D>> _codewordVector);
    int minimumWeight();
    void calcDistance();
    int minimumDistance();
    void display();
};
#endif
