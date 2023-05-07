#ifndef MATRYOSHKA_H
#define MATRYOSHKA_H

#include "matryoshka-entry.h"

class Matryoshka : public MatryoshkaEntry
{
public:
    Matryoshka();
    Matryoshka(Matryoshka &mat);
    ~Matryoshka();
    void add(MatryoshkaEntry &mat);
    void remove();
    int getCount();
    int getListSize();

private:
    MatryoshkaEntry *matList[10];
    int count = 0;
};

#endif // MATRYOSHKA_H
