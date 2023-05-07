#ifndef CAT_H
#define CAT_H

#include "matryoshka-entry.h"

class Cat : public MatryoshkaEntry
{
public:
    Cat();
    Cat(Cat &cat);
    ~Cat();
    void remove();
};

#endif // CAT_H
