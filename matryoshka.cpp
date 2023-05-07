#include "matryoshka.h"
#include <iostream>

Matryoshka::Matryoshka()
{

}

Matryoshka::Matryoshka(Matryoshka &mat)
{

}

Matryoshka::~Matryoshka()
{

}

// 参照渡し: ポインタ渡しとほぼ一緒
void Matryoshka::add(MatryoshkaEntry &mat)
{
    // アドレスが入るので、&
    matList[count] = &mat;
    count++;
}

void Matryoshka::remove()
{
    int matListSize = getListSize();

    for(int i=0; i<matListSize; i++){
        // グローバル配列の初期値は0なので、0以外の場合removeを実行
        if(matList[i] != 0) {
           matList[i]->remove();
        }
    }
    count = 0;
}

int Matryoshka::getCount()
{
    return count;
}

int Matryoshka::getListSize()
{
    return sizeof(matList) / sizeof(matList[0]);
}
