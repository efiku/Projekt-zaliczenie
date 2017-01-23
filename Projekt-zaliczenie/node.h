#pragma once
#include "mcoord.h"
#include <cstring>
#include <iostream>
class node :
    public mcoord
{
    int numb; //numer wierzchołka
    char str[512]; //nazwa wierzchołka
public:
    node();
    node(const node &source);
    node(int nb, char *st, double xx, double yy);
    ~node() override;
    double getX() const { return pcoord[0]; };
    double getY() const { return pcoord[1]; };
    const char * getVertexName() const { return str; };
    int getVertexNumber() const { return numb; };

    bool operator ==(const node &source) const{
        return this->numb == source.numb;
    }

    node & operator =(const node &source) {
        mcoord::operator=(source);
        strncpy_s(str, source.str, 512);
        numb = source.numb;
        return *this;
    }
    friend std::istream& operator >> (std::istream & input, node& o);
    friend std::ostream& operator << (std::ostream & out, node& o);
};