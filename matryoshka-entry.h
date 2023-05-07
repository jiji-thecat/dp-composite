#ifndef MATRYOSHKAENTRY_H
#define MATRYOSHKAENTRY_H

#include <QString>

class MatryoshkaEntry
{
public:
    MatryoshkaEntry();
    MatryoshkaEntry(MatryoshkaEntry &mat);
    ~MatryoshkaEntry();
    virtual void remove() = 0;

private:
    QString name;
};

#endif // MATRYOSHKAENTRY_H
