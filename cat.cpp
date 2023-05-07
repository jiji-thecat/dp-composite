#include "cat.h"
#include <iostream>


Cat::Cat()
{

}

Cat::Cat(Cat &cat)
{

}

Cat::~Cat()
{

}

void Cat::remove()
{
    delete this;
}
